#include<stdio.h>
#include<math.h>

float sol1(float,float,float); /*Declaració de les funcions que calculen cada solució de l'equació de segon grau*/
float sol2(float,float,float);

int main(void){
  float a;
  float b;
  float c;
  float x1;
  float x2;
  printf("\nEstableixi els coeficients a,b,c de ax^2+bx+c=0 :");
  printf("\na = ");
  scanf("%f",&a);
  printf("\nb = ");
  scanf("%f",&b);
  printf("\nc = ");
  scanf("%f",&c);
  if(b*b>4*a*c){
    x1=sol1(a,b,c);
    x2=sol2(a,b,c);
    printf("\nLes solucions són x1 = %.16G i x2 = %.16G\n",x1,x2);
  }
  else{
    printf("\nNo es compleix que b^2>4ac o a>0!\n");
  }
  return 0;
}

/*El codi fins aquí és idèntic al dels anteriors programes p2as.c i p2ad.c però ara s'han de tractar per separat les fñormules possiblement contaminades amb errors de cancel·lació*/
float sol1(float c1,float c2, float c3){/*Definició de les funcions que calculen les solucions*/
  float res;
  if(c2>0){
    res=-2.*c3/(c2+sqrtf(c2*c2-4*c1*c3)); /*Fórmula alternativa (prové de multiplicar pel conjugat*/
  }
  else{
    res=(-c2+sqrtf(c2*c2-4*c1*c3))/(2.*c1);
  }
  return res; /*Retorn de la solució*/
}

float sol2(float c1,float c2, float c3){/*Equivalent al cas anterior però amb l'altra solució*/
  float res;
  if(c2<0){
    res=2.*c3/(-c2+sqrtf(c2*c2-4*c1*c3)); 
  }
  else{
    res=(-c2-sqrtf(c2*c2-4*c1*c3))/(2.*c1);
  }
  return res;
}



