/* Problema 4 Pràctica 3*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795
#define tol 0.01

double f(double d)
{
  return log(d);
}

double d4f(double d)
{
  return -6./(d*d*d*d);
}

int main (void)
{
  int j,n=2;
  double a=1,b=2,h;
  double *x;
  double integral=0;
  double error=1;  

  while(error>tol)
  {
    error=0;
    h=(b-a)/n;
    x=(double *)malloc(n*sizeof(double));
    for(j=0;j<=n;j++)
    {
      x[j]=a+j*h;
    }

    for(j=0;j<n/2;j++)
    {
      integral=integral+h/3*(f(x[2*j])+4*f(x[2*j+1])+f(x[2*j+2]));
      if(fabs(d4f(a))>fabs(d4f(b)))
      {
        error=(b-a)*fabs(d4f(a))*h*h*h*h/180;
      }
      else
      {
        error=(b-a)*fabs(d4f(b))*h*h*h*h/180;
      }
    }
    n+=2;
  }

  printf("La integral dóna (SIMPSON) %.8G\t amb %d nodes i la cota de l'error és %.8G\n\n",integral,n-2,error);
  return 0;
}