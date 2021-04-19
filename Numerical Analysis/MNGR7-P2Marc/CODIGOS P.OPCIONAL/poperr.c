#include<stdio.h>
#include<math.h>

double g(double d)
{
  return pow(d,7)/pow(7*pow(d,3)+56*pow(d,2)+112*d+64,2);
}

int main(void)
{
  int k=2;
  int j;
  double ak;
  printf("Càlcul de l'error en la determinació d'sqrt(2) amb l'ALGORITME de pop.c:\n");
  ak=1;/*Per al càlcul d'sqrt(2) necessitem que a_0=1*/
  for(j=0;j<=k;j++)
  {
    ak=g(ak);/*a_k=a_(k+1)*/
    printf("\nIteració %d - Error = |sqrt(2)-prod(%d)| <= %.16G\n",j,j,ak/2*2);/*|sqrt(1+x)-prod(k)|<=a_(k+1)/2*(1+x)*/
  }
  printf("\nALGORITME - Error amb 3 iterats = |sqrt(2)-b_0*b_1*b_2| <= %.16G\n\n",ak/2*2);
  return 0;
}