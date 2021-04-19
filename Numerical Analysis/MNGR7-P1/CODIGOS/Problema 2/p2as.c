#include<stdio.h>
#include<math.h>

int main(void){
  float a;
  float b;/*Declaració de les variables on s'emmagatzemaran els coeficients*/
  float c;
  float x1;/*Declaració de les variables que emmagatzemaran les solucions*/
  float x2;
  printf("\nEstableixi els coeficients a,b,c de ax^2+bx+c=0 :");
  printf("\na = ");
  scanf("%f",&a);
  printf("\nb = ");
  scanf("%f",&b);/*Lectura dels coeficients llegits per pantalla*/
  printf("\nc = ");
  scanf("%f",&c);
  if((b*b>4*a*c)&&(a>0)){/*Càlcul de les solucions si es dona el cas que a>0 i b^2>4ac*/
    x1=(-b+sqrtf(b*b-4.*a*c))/(2.*a);/*Notis l'ús de la funció sqrtf en lloc de la funció sqrt*/
    x2=(-b-sqrtf(b*b-4.*a*c))/(2.*a);
    printf("\nLes solucions són x1 = %.16G i x2 = %.16G\n",x1,x2);/*Sortida per pantalla dels valors que tenen les solucions*/
  }
  else{
    printf("\nNo es compleix que b^2>4ac o a>0!\n");/*Missatge de l'error*/
  }
  return 0;
}