#include<stdio.h>
#include<math.h>

/*Codi equialent al programa p2as.c però en format double*/

int main(void){
  double a;
  double b;
  double c;
  double x1;
  double x2;
  printf("\nEstableixi els coeficients a,b,c de ax^2+bx+c=0 :");
  printf("\na = ");
  scanf("%lf",&a);
  printf("\nb = ");
  scanf("%lf",&b);
  printf("\nc = ");
  scanf("%lf",&c);
  if((b*b>4*a*c)&&(a>0)){
    x1=(-b+sqrt(b*b-4.*a*c))/(2.*a);/*Ara sí, s'empra la funció sqrt directament*/
    x2=(-b-sqrt(b*b-4.*a*c))/(2.*a);
    printf("\nLes solucions són x1 = %.16G i x2 = %.16G\n",x1,x2);
  }
  else{
    printf("\nNo es compleix que b^2>4ac o a>0!\n");
  }
  return 0;
}