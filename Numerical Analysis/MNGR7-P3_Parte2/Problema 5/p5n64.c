/* Problema 5 Pràctica 3, n=64*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795
#define extr 1.596071637983322

double f(double d)
{
  return exp(d)/d;
}

double ddf(double d)
{
  return (d*d-2*d+2)*exp(d)/(d*d*d);
}

int main (void)
{
  int j,n=64;
  double a=1,b=5,h; 
  double *x;
  double integral=0;
  double integral2=0;
  double error=0;
  double error2=0;

  x=(double *)malloc(n*sizeof(double));

  h=(b-a)/n;

  for(j=0;j<=n;j++)
  {
    x[j]=a+j*h;
  }

  for(j=0;j<n;j++)
  {
    integral=integral+h*(f(x[j+1])+f(x[j]))/2;
    if((x[j]<extr)&&(x[j+1]>extr))
    {
      if(fabs(ddf(x[j+1]))>fabs(ddf(x[j])))
      {
        if(fabs(ddf(x[j+1]))>fabs(ddf(extr)))
        {
          error=error+fabs(ddf(x[j+1]))/12*h*h*h;
        }
        else
        {
          error=error+fabs(ddf(extr))/12*h*h*h;
        }
      }
      else
      {
        if(fabs(ddf(x[j]))>fabs(ddf(extr)))
        {
          error=error+fabs(ddf(x[j]))/12*h*h*h;
        }
        else
        {
          error=error+fabs(ddf(extr))/12*h*h*h;
        }
      }
    }
    else
    {
      if(fabs(ddf(x[j+1]))>fabs(ddf(x[j])))
      {
        error=error+fabs(ddf(x[j+1]))/12*h*h*h;
      }
      else
      {
        error=error+fabs(ddf(x[j]))/12*h*h*h;
      }
    }
  }

  for(j=1;j<n;j++)
  {
    integral2=integral2+2*f(x[j]);
  }

  integral2=h/2*(integral2+f(a)+f(b));
  
  if(fabs(ddf(a))>fabs(ddf(b)))
  {
    error2=(b-a)*fabs(ddf(a))*h*h/12;
  }
  else
  {
    error2=(b-a)*fabs(ddf(b))*h*h/12;
  }

  printf("(n=64) La integral dóna (TRAPEZIS SIMPLE) \t%.8G i la cota de l'error és \t%.8G\n",integral,error);
  printf("(n=64) La integral dóna (TRAPEZIS COMPOST) \t%.8G i la cota de l'error és \t%.8G\n",integral2,error2);
  return 0;
}