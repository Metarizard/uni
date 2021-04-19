#include<stdio.h>
#include<math.h>

int main (void){
  float a;
  float b;/*Variables que emmagatzemen el valor dels costats del triangle*/
  float c;
  float p;/*Variable destinada a emmagatzemar el valor del semiperímetre*/
  float area;/*Variable destinada a emmagatzemar el valor de l'àrea del triangle*/
  printf("Quina és la longitud dels costats?\n");
  printf("\na = ");
  scanf("%f",&a);
  printf("\nb = ");
  scanf("%f",&b);
  printf("\nc = ");
  scanf("%f",&c);/*Introducció del valor dels costats per pantalla i posterior lectura*/
  p=(a+b+c)/2;
  area=sqrtf(p*(p-a)*(p-b)*(p-c));/*Assignació i càlcul dels valors p i area*/
  printf("\nL'àrea del triangle és %.16G\n",area);
  return 0;
}
  