#include<stdio.h>
#include<math.h>

float fs(float);

int main (void){
    float x0;
    float fx0;
    printf("\nOn vol avaluar la funció?\n");
    printf("x0 = ");
    scanf("%f",&(x0));
    fx0=fs(x0);
    printf("El valor f(x0) si avaluem en precisió simple és %.16G.\n\n",fx0);
    return 0;
}

float fs(float x){
    if (x==0){
        return 0.5;
    }
    else{
        return 2.*sinf(x/2)*sinf(x/2)/(x*x); /*Substitució trigonomètrica per tal d'evitar la cancel·lació produïda a l'exemple*/
    }
}

 /*Mateixa descripció que al codi p1as.c*/