#include<stdio.h>
#include<math.h>

double f(double d)
{
  return((7*pow(d,3)+56*pow(d,2)+112*pow(d,1)+64)/(pow(d,3)+24*pow(d,2)+80*pow(d,1)+64));
}

double g(double d)
{
  return pow(d,7)/pow(7*pow(d,3)+56*pow(d,2)+112*d+64,2);
}

int main(void)
{
  int k;
  int j;
  double x;
  double ak;
  double bj;/*Inicialització del productori*/
  double prodk=1;
  printf("De quin nombre vol calcular l'arrel?: ");
  scanf("%lf",&x);
  printf("\nFUNCIÓ SQRT - El valor de sqrt(%.16G) = %.16G\n",x,sqrt(x));/*Valor amb la funció sqrt() de C, només per comparar visualment*/
  ak=x-1;/*El mètode funciona si sqrt(x) és de la forma sqrt(1+(x-1)) => a_0=x-1*/
  printf("Determini 'k' de la fórmula: ");
  scanf("%d",&k);
  for(j=0;j<=k;j++)/*Càlcul de l'arrel emprant que prod(k) és aproximadament sqrt(1+x)*/
  {
    bj=f(ak);
    printf("\nb_%d = %.16G\n",j,bj);
    prodk=prodk*bj;
    printf("prod(%d) = %.16G\n",j,prodk);
    ak=g(ak);
    printf("a_%d = %.16G\n",j+1,ak);
  }
  printf("\nALGORITME - El valor de sqrt(%.16G) = %.16G\n",x,prodk);
  return 0;
}