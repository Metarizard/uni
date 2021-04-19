#include<stdio.h>
#include<math.h>

/*Codi idèntic al proposat a p5cs.c però en format de precisió doble*/

int main (void){
  double a;
  double b;
  double c;
  double area;
  printf("Quina és la longitud dels costats?\n");
  printf("\na = ");
  scanf("%lf",&a);
  printf("\nb = ");
  scanf("%lf",&b);
  printf("\nc = ");
  scanf("%lf",&c);
  if((a>=b)&&(b>=c)){
    area=1./2*sqrt(a*a*c*c-1./4*(a*a+c*c-b*b)*(a*a+c*c-b*b));
    printf("\nL'àrea del triangle és %.16G\n",area);
  }
  else{
    printf("\nLa longitud dels costats no està en ordre! És necessari que a>=b>=c\n");
  }
  return 0;
}
