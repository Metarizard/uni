#include<stdio.h>
#include<math.h>

int main (void)
{
  float alphas;/*Variables que emmagatzemaran el valor de l'arrel*/
  double alphad;
  float ress;/*Variables que emamagatzemaran el valor obtingut en avaluar f(alpha)=x^3-x-40*/ 
  double resd;
  
  printf("Procedim al càlcul de l'arrel real\n");
  alphas=cbrtf(20+1./9*sqrtf(32397))+cbrtf(20-1./9*sqrtf(32397));/*Assignació dels valors amb Cardano, ús de la funcio cbrt (cbrtf per a FLOAT) per al calcul d'arrels cúbiques*/
  alphad=cbrt(20+1./9*sqrt(32397))+cbrt(20-1./9*sqrt(32397));
  printf("\nEl resultat en precisió SIMPLE és\n");
  printf("%.8G",alphas);/*Resultats per pantalla*/
  printf("\nen precisió DOBLE és\n");
  printf("%.16G\n",alphad);
  ress=powf(alphas,3)-alphas-40;/*Assignació del valor que pren f(alpha)*/
  resd=pow(alphad,3)-alphad-40;
  printf("\nAvaluant el polinomi en dites solucions s'obté en SIMPLE:\n");/*Sortida per pantalla*/
  printf("%.8G\n",ress);
  printf("\nen DOBLE:\n");
  printf("%.16G\n",resd);
  return 0;
}
  