/* Problema 4 Pràctica 3*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795

int main (void)
{
  int j,n=14;
  double h=6;
  double *x;
  double *f;
  double integral=0;
  double integral2=0;

  x=(double *)malloc(n*sizeof(double));
  f=(double *)malloc(n*sizeof(double));

  for(j=0;j<=n;j++)
  {
      x[j]=h*j;
  }

  f[0]=37.2;
  f[1]=40.2;
  f[2]=44.4;
  f[3]=40.8;
  f[4]=44.1;
  f[5]=39.9;
  f[6]=36.3;
  f[7]=32.7;
  f[8]=29.7;
  f[9]=25.5;
  f[10]=23.4;
  f[11]=26.7;
  f[12]=31.2;
  f[13]=34.8;
  f[14]=36.9;

  for(j=0;j<n;j++)
  {
    integral=integral+6*(f[j+1]+f[j])/2;
  }

  for(j=0;j<n/2+1;j++)
  {
    integral2=integral2+h/3*(f[2*j]+4*f[2*j+1]+f[2*j+2]);
  }

  printf("La longitud és aproximadament (TRAPEZIS)\t %.8G m\n",integral);
  printf("La longitud és aproximadament (SIMPSON) \t %.8G m\n\n",integral2);
  return 0;
}