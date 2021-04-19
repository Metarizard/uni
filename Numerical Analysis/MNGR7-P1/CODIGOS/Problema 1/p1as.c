#include<stdio.h>
#include<math.h>

float fs(float); /*Declaració de la funció que calcularà f(x)*/

int main (void){
    float x0; /*Variable que emmagatzema el valor on volem avaluar la funció*/
    float fx0; /*Valor que pren la funció en x0*/
    printf("\nOn vol avaluar la funció?\n");
    printf("x0 = "); /*Per tal de veure l'error de cancel·lació introduirem al programa el valor x0=0.000012*/
    scanf("%f",&(x0)); /*Escaneig del valor introduit per pantalla*/
    fx0=fs(x0);
    printf("El valor f(x0) si avaluem en precisió simple és %.16G.\n\n",fx0); /*Sortida per pantalla del valor que pren la funció en x0*/
    return 0;
}

float fs(float x){/*Definició de la funció que calcula f(x)*/
    if (x==0){
        return 0.5; 
    }
    else{
        return (1-cosf(x))/(x*x); /*La funció 'cosf' tracta l'argument en precisió simple i el retorna en precisió simple també, al contrari que la funció 'cos'*/
    }
}