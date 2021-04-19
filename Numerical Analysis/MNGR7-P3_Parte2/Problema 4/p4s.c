/* Problema 4 Pràctica 3*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795
#define extr 0.5773502691896258

double f(double d)
{
  return 1./(1+d*d);
}

double d4f(double d)
{
  return 24*(5*d*d*d*d-10*d*d+1)/((d*d+1)*(d*d+1)*(d*d+1)*(d*d+1)*(d*d+1));
}

int main (void)
{
  int j,n=4;
  double a=0,b=1,h;
  double *x;
  double integral=0;
  double error=0;
  double error2=0;

  x=(double *)malloc(n*sizeof(double));

  h=(b-a)/n;

  for(j=0;j<=n;j++)
  {
    x[j]=a+j*h;
  }

  for(j=0;j<n/2;j++)
  {
    integral=integral+h/3*(f(x[2*j])+4*f(x[2*j+1])+f(x[2*j+2]));
    if((x[2*j]<extr)&&(x[2*j+2]>extr))
    {
      if(fabs(d4f(x[2*j+2]))>fabs(d4f(x[2*j])))
      {
        if(fabs(d4f(x[2*j+2]))>fabs(d4f(extr)))
        {
          error=error+fabs(d4f(x[2*j+2]))/90*h*h*h*h*h;
        }
        else
        {
          error=error+fabs(d4f(extr))/90*h*h*h*h*h;
        }
      }
      else
      {
        if(fabs(d4f(x[2*j]))>fabs(d4f(extr)))
        {
          error=error+fabs(d4f(x[2*j]))/90*h*h*h*h*h;
        }
        else
        {
          error=error+fabs(d4f(extr))/90*h*h*h*h*h;
        }
      }
    }
    else
    {
      if(fabs(d4f(x[2*j+2]))>fabs(d4f(x[2*j])))
      {
        error=error+fabs(d4f(x[2*j+2]))/90*h*h*h*h*h;
      }
      else
      {
        error=error+fabs(d4f(x[2*j]))/90*h*h*h*h*h;
      }
    }
  }

  if(fabs(d4f(a))>fabs(d4f(b)))
  {
    if(fabs(d4f(a))>fabs(d4f(extr)))
    {
      error2=(b-a)*fabs(d4f(a))*h*h*h*h/180;
    }
    else
    {
      error2=(b-a)*fabs(d4f(extr))*h*h*h*h/180;
    }
  }
  else
  {
    error2=(b-a)*fabs(d4f(b))*h*h*h*h/180;
  }

  printf("La integral dóna (SIMPSON SIMPLE) \t%.8G i la cota de l'error és %.8G\n",integral,error);
  printf("La integral dóna (SIMPSON COMPOST) \t%.8G i la cota de l'error és %.8G\n\n",integral,error2);
  return 0;
}