/* Problema 2 Pràctica 3, n=64*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795


double f(double d)
{
  return 1./(1+25*d*d);
}

int main (void)
{
  int i,j,n=64,np=180;
  double *evalj;
  double *fevalj;
  double *xj; /*xj=-1+j*2/n*/
  double *xjc; /*Chebyshev*/
  double *fj;
  double *fjc;
  double *poli;
  double *polic;
  double **matriu;
  double **matriuc;

  xj=(double *)malloc(np*sizeof(double));
  xjc=(double *)malloc(np*sizeof(double));
  fj=(double *)malloc(np*sizeof(double));
  fjc=(double *)malloc(np*sizeof(double));
  matriu=(double **)malloc(n*sizeof(double));
  matriuc=(double **)malloc(n*sizeof(double));

  for(j=0;j<n;j++)
  {
    xj[j]=-1+j*2./(n-1);
    /*printf("\nx_%d = %.3G",j,xj[j]);*/
    xjc[j]=cos((2.*j+1.)*PI/(2*n));
    /*printf("\nx_%d (c) = %.3G",j,xjc[j]);*/
    fj[j]=f(xj[j]);
    fjc[j]=f(xjc[j]);
    matriu[j]=(double *)malloc(n*sizeof(double));
    matriuc[j]=(double *)malloc(n*sizeof(double));
  }

  for(j=n;j<=np;j++)
  {
    xj[j]=-1;
    xjc[j]=cos(PI/(2*n));
    fj[j]=f(1);
    fjc[j]=f(xjc[j]);
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      matriu[i][j]=0;
      matriuc[i][j]=0;
    }
  }

 
  for(i=0;i<n;i++)
  {
      matriu[i][0]=fj[i];
      matriuc[i][0]=fjc[i];
  }
  

  for(j=1;j<n;j++)
  {
    for(i=0;i<n-j;i++)
    {
      matriu[i][j]=(matriu[i+1][j-1]-matriu[i][j-1])/(xj[j+i]-xj[i]);
      matriuc[i][j]=(matriuc[i+1][j-1]-matriuc[i][j-1])/(xjc[j+i]-xjc[i]);
    }
  }
  
   /*for(i=0;i<n;i++)
  {
    printf("\n");
    for(j=0;j<n;j++)
    {
      printf("%.3G\t",matriu[i][j]);
    }
  }

  printf("\n");
  
  for(i=0;i<n;i++)
  {
    printf("\n");
    for(j=0;j<n;j++)
    {
      printf("%.3G\t",matriuc[i][j]);
    }
  }*/


  poli=(double *)malloc(np*sizeof(double));
  polic=(double *)malloc(np*sizeof(double));
  evalj=(double *)malloc(np*sizeof(double));
  fevalj=(double *)malloc(np*sizeof(double));
  for(j=0;j<=np;j++)
  {
    poli[j]=0;
    polic[j]=0;
    evalj[j]=-0.989+j*0.011;
    fevalj[j]=f(evalj[j]);
  }
  
  for(j=np;j>=0;j--)
  {
    for(i=n-1;i>=0;i--)
    {
      poli[j]=poli[j]*(fabs(evalj[j])-xj[i])+(matriu[0][i]);
      polic[j]=polic[j]*(fabs(evalj[j])-xjc[i])+(matriuc[0][i]);
    }
  }

  for(j=0;j<=np;j++)
  {
      printf("\n%.8G\t%.8G\t%.8G\t%.8G\t%.8G\t%.8G\t%.8G\t%.8G",evalj[j],xj[j],xjc[j],poli[j],polic[j],fj[j],fjc[j],fevalj[j]);
  }

  free(xj);
  free(xjc);
  free(fj);
  free(fjc);
  free(poli);
  free(polic);
  free(matriu);
  free(matriuc);
  free(evalj);
  free(fevalj);

  return 0;
}