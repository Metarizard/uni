#include<stdio.h>
#include<math.h>

/*Codi idèntic a p5as.c en format double*/

int main (void){
  double a;
  double b;
  double c;
  double p;
  double area;
  printf("Quina és la longitud dels costats?\n");
  printf("\na = ");
  scanf("%lf",&a);
  printf("\nb = ");
  scanf("%lf",&b);
  printf("\nc = ");
  scanf("%lf",&c);
  p=(a+b+c)/2;
  area=sqrt(p*(p-a)*(p-b)*(p-c));
  printf("\nL'àrea del triangle és %.16G\n",area);
  return 0;
}
  