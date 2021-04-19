/*Problema individual n arbirtrari*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define tol 1e-6
#define PI 3.1415926535897932384626433832795

double pl(int n, double x)/*Recurrència polinomis Legendre*/
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

double pc(int n, double x)/*Recurrència polinomis Chebyshev*/
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

/*Recurrència derivades polinomis*/

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

/*Definició funcions a integrar*/

double f1(double x)
{
    return exp(-x*x); 
} 

double f2(double x)
{
    return exp(-x*x)/cbrt(1-x*x);
}

/*Funció exponent natural*/

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

/*Recurrència de la integral que dóna el terme independent del sistema de Chebyshev*/

double irec(int n, double a, double b)
{
  if(n==0)
  {
    return asin(b)-asin(a);
  }
  else
  {
    if(n==1)
    {
      return sqrt(1-a*a)-sqrt(1-b*b);
    }
    else
    {
      return (pot(a,n-1)*sqrt(1-a*a)-pot(b,n-1)*sqrt(1-b*b)+(n-1)*irec(n-2,a,b))/n;
    }
  }
}

/*Polinomi que apareix a la n-èssima derivada de e^-(x^2)*/

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

/*Funció factorial*/

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
    int i,j,k,m=2,n,arrl=0,arrc=0,il,ic;/*Índexs i comptadors*/ 
    double iterat,exte,extd,multl,multc,sumal,sumac;/*Variables auxiliars càlculs*/
    double *x;
    double *al;/*Intervals*/
    double *ac;
    double *newtl;/*Arrels*/
    double *newtc;
    double *ail;/*Coeficients*/
    double *aic;
    double **matriul;/*Matriu de coeficients sistema*/
    double **matriuc;
    double *bl;/*Termes independents sistema*/
    double *bc;

    printf("Introdueixi el grau dels polinomis: ");
    scanf("%d",&n);
    
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


    /*Coeficients a_i Legendre i Chebyshev mètode de Gauss (ressolució sistema)*/
    
    ail=(double *)malloc(n*sizeof(double));
    aic=(double *)malloc(n*sizeof(double));
    matriul=(double **)malloc(n*sizeof(double));
    matriuc=(double **)malloc(n*sizeof(double));
    bl=(double *)malloc(n*sizeof(double));
    bc=(double *)malloc(n*sizeof(double));
    
    for(i=0;i<n;i++)
    {
      matriul[i]=(double *)malloc(n*sizeof(double));
      matriuc[i]=(double *)malloc(n*sizeof(double));
      bc[i]=irec(i,-1,1);
      bl[i]=(pot(1,i+1)-pot(-1,i+1))/(i+1);
    }
    
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
	    matriul[i][j]=pot(newtl[j],i);
        matriuc[i][j]=pot(newtc[j],i);
      }
    }

    for(k=0;k<n-1;k++)
    {
        for(i=k+1;i<n;i++)
        {
            multl=matriul[i][k]/matriul[k][k];
            multc=matriuc[i][k]/matriuc[k][k];
            for(j=k;j<n;j++)
            {
                matriul[i][j]=matriul[i][j]-multl*matriul[k][j];
                matriuc[i][j]=matriuc[i][j]-multc*matriuc[k][j];
            }
            bl[i]=bl[i]-multl*bl[k];
            bc[i]=bc[i]-multc*bc[k];
        }
    }

    for(i=0;i<n;i++)
    {
        ail[i]=aic[i]=0;
    }

    for(i=n-1;i>=0;i--)
    {
        sumal=0;
        sumac=0;
        for(j=i+1;j<n;j++)
        {
            sumal=sumal+matriul[i][j]*ail[j];
            sumac=sumac+matriuc[i][j]*aic[j];
        }
        ail[i]=(bl[i]-sumal)/matriul[i][i];
        aic[i]=(bc[i]-sumac)/matriuc[i][i];
    }
    printf("\n");
    
    printf("\nCoeficients Legendre sistema\t");

    for(i=0;i<n;i++)
    {
        printf("%.16G\t",ail[i]);
    }

    printf("\n");
    
    printf("\nCoeficients Chebyshev sistema\t");

    for(i=0;i<n;i++)
    {
        printf("%.16G\t",aic[i]);
    }

    /*Coeficients a_i Legendre i Chebyshev fórmules*/

    printf("\n");
    
    printf("\nCoeficients Legendre fórmula\t");

    for(i=0;i<n;i++)
    {
        ail[i]=2./((1-newtl[i]*newtl[i])*dpl(n,newtl[i])*dpl(n,newtl[i]));
        aic[i]=PI/n;
        printf("%.16G\t",ail[i]);
    }

    printf("\n");
    
    printf("\nCoeficients Chebyshev fórmula\t");

    for(i=0;i<n;i++)
    {
        printf("%.16G\t",aic[i]);
    }
    return 0;
}