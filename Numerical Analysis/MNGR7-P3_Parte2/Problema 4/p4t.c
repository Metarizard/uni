/* Problema 4 Pràctica 3*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795

double f(double d)/*Definició d'f*/
{
  return 1./(1+d*d);
}

double ddf(double d)/*Definició de la segona derivada d'f*/
{
  return 2*(3*d*d-1)/((d*d+1)*(d*d+1)*(d*d+1));
}

int main (void)
{
  int j,n=4;/*j index per als bucles, n divisions de l'interval*/
  double a=0,b=1,h;/*a,b limits interval, h longitud de cada divisió*/
  double *x;/*nodes*/
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

  for(j=0;j<n;j++)/*Càlcul de la integral i de l'error amb els dos mètodes*/
  {
    integral=integral+h*(f(x[j+1])+f(x[j]))/2;
    if(fabs(ddf(x[j+1]))>fabs(ddf(x[j])))/*Error simple, es calcula l'error comès a cada intevalet [x_j,x_(j+1)]*/
    {
      error=error+fabs(ddf(x[j+1]))/12*h*h*h;
    }
    else
    {
      error=error+fabs(ddf(x[j]))/12*h*h*h;
    }
  }

  for(j=1;j<n;j++)
  {
    integral2=integral2+2*f(x[j]);
  }

  integral2=h/2*(integral2+f(a)+f(b));
  
  if(fabs(ddf(a))>fabs(ddf(b)))/*Fórmula de l'error compost*/
  {
    error2=(b-a)*fabs(ddf(a))*h*h/12;
  }
  else
  {
    error2=(b-a)*fabs(ddf(b))*h*h/12;
  }

  printf("La integral dóna (TRAPEZIS SIMPLE) \t%.8G i la cota de l'error és \t%.8G\n",integral,error);
  printf("La integral dóna (TRAPEZIS COMPOST) \t%.8G i la cota de l'error és \t%.8G\n",integral2,error2);
  return 0;
}