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

double f(double x)
{
    return 1./4*sqrt(16+x*x/(x*x-4)); 
} 

double d2f(double x)
{
    return (51*pot(x,4)-128*x*x-256)/(pot(x*x-4,4)*sqrt(pot(x*x/(x*x-4)+16,3)));
}

int main(void)
{
    int i,j,m=2,n=1,arrl,il,nl,nt;
    double iterat,exte,extd,intl=0,intt=0,a,b,errort=1,max;
    double *x;
    double *y;
    double *al;
    double *newtl;
    double *ail;

    printf("\nIntrodueixi l'interval d'integració [a,b] amb |a|<2 i |b|<2 de la integral");
    printf("\na: ");
    scanf("%lf",&a);
    printf("\nb: ");
    scanf("%lf",&b);

    if(fabs(a)>fabs(b))
    {
        max=fabs(a);
    }
    else
    {
        max=fabs(b);
    }

    /*Error trapezis*/

    while(errort>tol)
    {
        errort=fabs(pot(b-a,3)*d2f(max)/(12*n*n));
        n+=1;
    }

    nt=n;

    y=(double *)malloc(n*sizeof(double));

    /*Nodes trapezis*/

    for(j=0;j<n;j++)
    {
        y[j]=a+j*(b-a)/(n-1);
    }

    /*Integral trapezis*/

    for(j=0;j<n-1;j++)
    {
        intt=intt+(b-a)*(f(y[j+1])+f(y[j]))/(2*(n-1));
    }

    n=2;

    while(fabs(intt-intl)>tol)
    {
        al=(double *)malloc(2*n*sizeof(double));
        newtl=(double *)malloc(n*sizeof(double));
        arrl=0;
        il=0;
        intl=0;
        while(arrl<n)
        {
            arrl=0;
            il=0;
            x=(double *)malloc(m*sizeof(double));
            for(i=0;i<m;i++)
            {
                x[i]=-1+i*2./(m-1);
            }
            /*Determinació intervals arrels polinomi Legendre grau n*/
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
            m+=1;
        }
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

        ail=(double *)malloc(n*sizeof(double));

        for(i=0;i<n;i++)
        {
            ail[i]=2./((1-newtl[i]*newtl[i])*dpl(n,newtl[i])*dpl(n,newtl[i]));
        }   

        for(i=0;i<n;i++)
        {
            intl=intl+(b-a)*ail[i]*f(((b-a)*newtl[i]+(b+a))/2)/2;
        }
        n+=1;
    }

    nl=n;
    
    printf("\nLa integral val:");
    printf("\n(TRAPEZIS amb %d nodes)\t %.16G\tamb error %.16G\n",nt,intt,errort);
    printf("\n(LEGENDRE amb %d nodes)\t %.16G\n",nl,intl);

    return 0;
}