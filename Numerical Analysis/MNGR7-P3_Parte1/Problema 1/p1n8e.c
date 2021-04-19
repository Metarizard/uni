/* Problema 1 Pràctica 3, n=8*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795

double f(double d)
{
  if((fabs(d)>=0.7)&&(fabs(d)<=1))
  {
    return -1;
  }
  else
  {
    return 1;
  }
}

int main (void)
{
  int i,j,n=8,np=180,index=0;
  double err=0; 
  double *evalj; /*coordenades 'x' dels punts a representar*/
  double *fevalj; /*coordenades 'y' dels punts a representar amb la funció original*/
  double *xj; /*nodes xj=-1+j*2/n*/
  double *fj; /*imatge dels nodes*/
  double *poli; /*coordenades 'y' dels punts a representar amb el polinomi interpolador*/
  double **matriu; /*matriu que emmagatzema les diferències dividides*/

  xj=(double *)malloc(np*sizeof(double));
  fj=(double *)malloc(np*sizeof(double));
  matriu=(double **)malloc(n*sizeof(double));

  for(j=0;j<n;j++)
  {
    xj[j]=-1+j*2./(n-1);
    /*printf("\nx_%d = %.3G",j,xj[j]);*/
    fj[j]=f(xj[j]);
    matriu[j]=(double *)malloc(n*sizeof(double));
  }

  for(j=n;j<=np;j++)
  {
    xj[j]=1;
    fj[j]=-1;
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      matriu[i][j]=0;
    }
  }

 
  for(i=0;i<n;i++)
  {
      matriu[i][0]=fj[i];
  }
  

  for(j=1;j<n;j++)
  {
    for(i=0;i<n-j;i++)
    {
      matriu[i][j]=(matriu[i+1][j-1]-matriu[i][j-1])/(xj[j+i]-xj[i]);
    }
  }
  
  /*for(i=0;i<n;i++)
  {
    printf("\n");
    for(j=0;j<n;j++)
    {
      printf("%.3G\t",matriu[i][j]);
    }
  }*/


  poli=(double *)malloc(np*sizeof(double));
  evalj=(double *)malloc(np*sizeof(double));
  fevalj=(double *)malloc(np*sizeof(double));

  for(j=0;j<=np;j++)
  {
    poli[j]=0;
    evalj[j]=-0.989+j*0.011;
    fevalj[j]=f(evalj[j]);
  }
  
  for(j=np;j>=0;j--)
  {
    for(i=n-1;i>=0;i--)
    {
      poli[j]=poli[j]*(-fabs(evalj[j])-xj[i])+(matriu[0][i]);
    }
  }
  
  for(j=0;j<=np;j++)
  {
    if(fabs(poli[j]-fevalj[j])>err)
    {
      err=fabs(poli[j]-fevalj[j]);
      index=j;
    }
  }

  printf("\nL'error màxim es comet a |p(%.4G)-f(%.4G)| = %.8G,\t p(x) = %.8G, f(x) = %.8G\n\n",evalj[index],evalj[index],err,poli[index],fevalj[index]);


  free(xj);
  free(fj);
  free(poli);
  free(matriu);
  free(evalj);
  free(fevalj);

  return 0;
}