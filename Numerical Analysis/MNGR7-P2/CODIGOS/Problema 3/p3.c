#include <stdio.h>
#include <math.h>
#define tol 1.e-15

int main(void){
  double x;
  double y;
  double z;
  double w;
  double e;
  double xn[9];
  int n=0, j;
 
  w=200;
  z=7.413302725857898; /*La solució en double trobada als apartats anteriors que dóna exactament 0 en avaluar g(z), no es pot obtenir amb més precisió el valor de l'arrel en double*/
  x=6;/*Llavor inicial*/
  xn[0]=x;
  
  while(n<5)/*Fent proves s'ha comprovat que amb més iteracions el valor no canvia*/
  {
    w=x-(2*(x*x*x-x-400)*(3*x*x-1)/(2*(3*x*x-1)*(3*x*x-1)-(x*x*x-x-400)*(6*x)));
    xn[n]=x;
    n++;
    e=fabs(w-z)/fabs(x-z); /*utilitzant que tenim la solució amb 16 xifres significatives de l'exercici 2, comparem cada iteració amb aquest valor per veure com el nombre de xifres significatives va augmentant aproximadament de tres en tres en cada iteració com volíem veure */
    x=w;
    printf("%d ---- %.16G\n", n, x);
    printf(" e=%.16G\n\n", e);
  }
    
  for(j=2; j<n;j++)
  {
    e=(fabs(xn[j]-xn[j-1]))/pow(fabs(xn[j-1]-xn[j-2]),4); 
    printf("e(ordre4)=%.16G\n", e);
  }
  printf("\n");
    
  for(j=2; j<n;j++)
  {
    e=(fabs(xn[j]-xn[j-1]))/pow(fabs(xn[j-1]-xn[j-2]),2); 
    printf("e(ordre2)=%.16G\n", e);
  }  
  printf("\n");
    
  for(j=2; j<n;j++)
  {
    e=(fabs(xn[j]-xn[j-1]))/pow(fabs(xn[j-1]-xn[j-2]),3); /*si veiem que aquest número es manté estable al llarg de les iteracions, podrem afirmar que tenim ordre de convergència 3*/
    printf("e(ordre3)=%.16G\n", e);
  }
  y=2*x*x-1;
  if (fabs(y)<tol)
  { /*Comprova que la derivada no sigui 0 en l'error */
    printf("La derivada és 0 \a\a\n");
  }
  printf("la solució és %.16G amb %d iteracions \n\n", x, n);
  return 0;
 
}

