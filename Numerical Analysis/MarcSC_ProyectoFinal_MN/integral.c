/*Problema individual n arbitrari*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define tol 1e-6
#define PI 3.1415926535897932384626433832795

double pl(int n, double x)
{
    if((n==0)||(n==1))
    {
        if(n==0)
        {
            return 1;
        }
        else
        {
            return x;
        }
    }
    else
    {
        return ((2*n-1)*x*pl(n-1,x)-(n-1)*pl(n-2,x))/n;
    }
}

double pc(int n, double x)
{
    if((n==0)||(n==1))
    {
        if(n==0)
        {
            return 1;
        }
        else
        {
            return x;
        }
    }
    else
    {
        return 2*x*pc(n-1,x)-pc(n-2,x);
    }
}

double dpl(int n, double x)
{
    if((n==0)||(n==1))
    {
        if(n==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return (-n*x*pl(n,x)+n*pl(n-1,x))/(1-x*x);
    }
}

double dpc(int n, double x)
{
    if((n==0)||(n==1))
    {
        if(n==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return (-n*x*pc(n,x)+n*pc(n-1,x))/(1-x*x);
    }
}

double pot(double x, int n)
{
  int i;
  double pot=1;
  
  if(n==0)
  {
    return pot;
  }
  else
  {
    for(i=0;i<n;i++)
    {
      pot=pot*x;
    }
    return pot;
  }
}

double f1(double x)
{
    return exp(-x*x); 
} 

double f2(double x)
{
    return exp(-x*x)/cbrt(1-x*x);
}

double f2mod(double x)
{
    return exp(-sin(x)*sin(x))*cbrt(cos(x));
}

double d2f2mod(double x)
{
    return exp(-pot(sin(x),2))*((36*pot(cos(x),4)+30*pot(cos(x),2)-2)*pot(sin(x),2)-18*pot(cos(x),4)-3*pot(cos(x),2))/(9*cbrt(pot(cos(x),5)));
}

double pe(int n, double x)
{
    if((n==0)||(n==1))
    {
        if(n==0)
        {
            return 1;
        }
        else
        {
            return -2*x;
        }
    }
    else
    {
        return -2*x*pe(n-1,x)-2*(n-1)*pe(n-2,x);
    }
}

double fact(int n)
{
    int i;
    double prod=1;
    if(n==0)
    {
        prod=1;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            prod=prod*i;
        }
    }
    return prod;
}

int main(void)
{
    int i,j,k,m=2,n,arrl=0,arrc=0,il,ic;
    double iterat,exte,extd,int1l=0,int1c=0,int2l=0,int2c=0,int1t=0,int2t=0,int2tmod=0,a1,b1,a2,b2,error1l,error1t,error2t;
    double *x;
    double *al;
    double *ac;
    double *newtl;
    double *newtc;
    double *ail;
    double *aic;

    printf("Introdueixi el grau dels polinomis: ");
    scanf("%d",&n);
    printf("\nIntrodueixi l'interval d'integració [a1,b1] de la primera integral");
    printf("\na1: ");
    scanf("%lf",&a1);
    printf("\nb1: ");
    scanf("%lf",&b1);
    printf("\nIntrodueixi l'interval d'integració [a1,b1] de la primera integral");
    printf("\na2: ");
    scanf("%lf",&a2);
    printf("\nb2: ");
    scanf("%lf",&b2);
    printf("\nIntrodueixi el nombre de trapezis sobre els quals integrar");
    printf("\nk: ");
    scanf("%d",&k);

    al=(double *)malloc(2*n*sizeof(double));
    ac=(double *)malloc(2*n*sizeof(double));
    newtl=(double *)malloc(n*sizeof(double));
    newtc=(double *)malloc(n*sizeof(double));

    /*Determinació intervals*/
    while((arrl<n)||(arrc<n))
    {
        x=(double *)malloc(m*sizeof(double));
        for(i=0;i<m;i++)
        {
            x[i]=-1+i*2./(m-1);
        }
        /*Determinació intervals arrels polinomi Legendre grau n*/
        if(arrl<n)
        {
            arrl=0;
            il=0;
            for(i=0;i<m-1;i++)
            {
                if(pl(n,x[i])*pl(n,x[i+1])<0)
                {
                    arrl+=1;
                    al[il]=x[i];
                    al[il+1]=x[i+1];
                    il+=2;
                }
            }
        }
        /*Determinació intervals arrels polinomi Chebyshev grau n*/
        if(arrc<n)
        {
            arrc=0;
            ic=0;
            for(i=0;i<m-1;i++)
            {
                if(pc(n,x[i])*pc(n,x[i+1])<0)
                {
                    arrc+=1;
                    ac[ic]=x[i];
                    ac[ic+1]=x[i+1];
                    ic+=2;
                }
            }
        }
        m+=1;
    }
    
    /*Mètode Bisecció + Newton per al càlcul de les arrels*/

    for(i=0;i<n;i++)
    {
        newtl[i]=(al[2*i]+al[2*i+1])/2;
        exte=al[2*i];
        extd=al[2*i+1];
        for(j=0;j<2;j++)
        {
            if(pl(n,newtl[i])*pl(n,exte)<0)
            {
                newtl[i]=(newtl[i]+exte)/2;
                extd=newtl[i];
            }
            else
            {
                newtl[i]=(newtl[i]+extd)/2;
                exte=newtl[i];
            }
        }
        iterat=newtl[i];
        newtl[i]=iterat-pl(n,iterat)/(dpl(n,iterat));

        while(fabs(newtl[i]-iterat)>tol)
        {
            iterat=newtl[i];
            newtl[i]=iterat-pl(n,iterat)/(dpl(n,iterat));
        }
    }

    for(i=0;i<n;i++)
    {
        newtc[i]=(ac[2*i]+ac[2*i+1])/2;
        exte=ac[2*i];
        extd=ac[2*i+1];
        for(j=0;j<2;j++)
        {
            if(pc(n,newtc[i])*pc(n,exte)<0)
            {
                newtc[i]=(newtc[i]+exte)/2;
                extd=newtc[i];
            }
            else
            {
                newtc[i]=(newtc[i]+extd)/2;
                exte=newtc[i];
            }
        }
        iterat=newtc[i];
        newtc[i]=iterat-pc(n,iterat)/(dpc(n,iterat));

        while(fabs(newtc[i]-iterat)>tol)
        {
            iterat=newtc[i];
            newtc[i]=iterat-pc(n,iterat)/(dpc(n,iterat));
        }

    }

    printf("\n");

    /*Coeficients a_i Legendre i Chebyshev*/

    ail=(double *)malloc(n*sizeof(double));
    aic=(double *)malloc(n*sizeof(double));

    for(i=0;i<n;i++)
    {
        ail[i]=2./((1-newtl[i]*newtl[i])*dpl(n,newtl[i])*dpl(n,newtl[i]));
        aic[i]=PI/n;
    }


    /*Càlcul de les integrals*/

    for(i=0;i<n;i++)
    {
        int1l=int1l+(b1-a1)*ail[i]*f1(((b1-a1)*newtl[i]+(b1+a1))/2)/2;
        int1c=int1c+(b1-a1)*aic[i]*f1(((b1-a1)*newtc[i]+(b1+a1))/2)*sqrt(1-(2*((b1-a1)*newtc[i]+(b1+a1))/2-(b1+a1))*(2*((b1-a1)*newtc[i]+(b1+a1))/2-(b1+a1))/((b1-a1)*(b1-a1)))/2;
        int2l=int2l+(b2-a2)*ail[i]*f2(((b2-a2)*newtl[i]+(b2+a2))/2)/2;
        int2c=int2c+(b2-a2)*aic[i]*f2(((b2-a2)*newtc[i]+(b2+a2))/2)*sqrt(1-(2*((b2-a2)*newtc[i]+(b2+a2))/2-(b2+a2))*(2*((b2-a2)*newtc[i]+(b2+a2))/2-(b2+a2))/((b2-a2)*(b2-a2)))/2;
    }

    /*Trapezis*/

    x=(double *)malloc((k+1)*sizeof(double));

    for(j=0;j<=k;j++)
    {
        x[j]=a1+j*(b1-a1)/k;
    }

    for(j=0;j<k;j++)
    {
        int1t=int1t+(b1-a1)*(f1(x[j+1])+f1(x[j]))/(2*k);
    }

    for(j=0;j<=k;j++)
    {
        x[j]=a2+j*(b2-a2)/k;
    }

    for(j=0;j<k;j++)
    {
        int2t=int2t+(b2-a2)*(f2(x[j+1])+f2(x[j]))/(2*k);
    }

    /*Errors primera integral*/

    error1l=fabs(2*pe(2*n,0)*exp(-0*0)/(fact(2*n)*(2*n+1)));
    error1t=fabs(pot(b1-a1,3)*pe(2,0)/(12*k*k));

    /*Integrals amb canvi de variable*/

    a2=asin(a2);
    b2=asin(b2);

    for(j=0;j<=k;j++)
    {
        x[j]=a2+j*(b2-a2)/k;
    }

    for(j=0;j<k;j++)
    {
        int2tmod=int2tmod+(b2-a2)*(f2mod(x[j+1])+f2mod(x[j]))/(2*k);
    }
     
    /*Error trapezis segona integral modificada*/

    if(fabs(d2f2mod(0))>fabs(d2f2mod(x[k-1])))
    {
        error2t=fabs(pot(x[k-1]-a2,3)*d2f2mod(0)/(12*(k-1)*(k-1)))+fabs((b2-a2)*f2mod(x[k-1])/(2*k));
    }
    else
    {
        error2t=fabs(pot(x[k-1]-a2,3)*d2f2mod(x[k-1])/(12*(k-1)*(k-1)))+fabs((b2-a2)*f2mod(x[k-1])/(2*k));
    }
   

    printf("\nLa primera integral val:");
    printf("\n(LEGENDRE) %.16G\t(CHEBYSHEV) %.16G\t(TRAPEZIS) %.16G\n",int1l,int1c,int1t);
    printf("\nLa segona integral val:");
    printf("\n(LEGENDRE) %.16G\t(CHEBYSHEV) %.16G\t(TRAPEZIS) %.16G\t(TRAPEZIS MOD) %.16G\n",int2l,int2c,int2t,int2tmod);
    printf("L'error de LEGENDRE de la primera integral és %.16G\n",error1l);
    printf("L'error dels TRAPEZIS de la primera integral és %.16G\n",error1t);
    printf("L'error dels TRAPEZIS de la segona integral MODIFICADA és %.16G\n",error2t);
    return 0;
}