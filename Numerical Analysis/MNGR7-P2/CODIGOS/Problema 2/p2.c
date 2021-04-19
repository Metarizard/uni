#include <stdio.h>
#include <math.h>
#define tol 1.e-15

int main(void)
{
  double x;/*Iterat del problema*/
  double y;/*Variable auxiliar que emmagatzemrà l'iterat previ*/
  double b;/*Terme de la fórmula de la iteració*/
  int n=0;/*Nombre d'iteracions*/
  int j;/*Variable del bucle*/
  double xn[9];/*Vector que guarda els iterats*/
  double e;/*Variable per al càlcul de l'ordre*/
  
  y=1;/*Inicialitzacions, y inicialment és totalment aleatori per tal que entri al bucle*/
  x=6;
  b=1./(3*x*x-1);
  while(fabs(x-y)>tol && n<1000)/*S'atura a certa precisió o abans de 1000 iteracions*/
  {
    y=x;
    x=x-b*(x*x*x-x-400);
    b=b*(2-(3*x*x-1)*b);
    xn[n]=x;
    n++;
    printf("%d ---- %.16G\n", n, x);/*Sortida per pantalla*/
    printf("La b dóna %.16G \n\n", b);
  }
  printf("\n");
  
  /*Determinació de l'ordre*/
  for(j=2; j<n; j++)
  {
    e=(fabs(xn[j]-xn[j-1]))/(fabs(xn[j-1]-xn[j-2]));
    printf("e(ordre1)=%.16G\n", e);
  }
  printf("\n");
 
  for(j=2; j<n; j++){
    e=(fabs(xn[j]-xn[j-1]))/(fabs(xn[j-1]-xn[j-2])*fabs(xn[j-1]-xn[j-2]));
    printf("e(ordre2)=%.16G\n", e);
  }
  printf("\n");
 
  for(j=2; j<n; j++){
    e=(fabs(xn[j]-xn[j-1]))/(fabs(xn[j-1]-xn[j-2])*fabs(xn[j-1]-xn[j-2])*fabs(xn[j-1]-xn[j-2]));
    printf("e(ordre3)=%.16G\n", e);
  }
  printf("\n");
 
  printf("La solució és %.16G amb %d iteracions \n\n", x, n);
  return 0;
}
