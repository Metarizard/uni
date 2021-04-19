#include<stdio.h>
#include<math.h>

int main (void){
  float a;
  float b;
  float c;
  float area;
  printf("Quina és la longitud dels costats a>=b>=c?\n");
  printf("\na = ");
  scanf("%f",&a);
  printf("\nb = ");
  scanf("%f",&b);
  printf("\nc = ");
  scanf("%f",&c);
  if((a>=b)&&(b>=c)){
    area=1./2*sqrtf(a*a*c*c-1./4*(a*a+c*c-b*b)*(a*a+c*c-b*b));/*Fórmula alternativa per al càlcul de l'àrea del triangle*/
    printf("\nL'àrea del triangle és %.16G\n",area);
  }
  else{
    printf("\nLa longitud dels costats no està en ordre! És necessari que a>=b>=c\n");
  }
  return 0;
}
  