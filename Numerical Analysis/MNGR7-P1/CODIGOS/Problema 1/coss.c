#include<stdio.h>
#include<math.h>

int main (void){
    float x0;
    float cosx0;
    printf("\nOn vol avaluar la funció cos(x)?\n");
    printf("x0 = ");
    scanf("%f",&(x0));
    cosx0=cosf(x0);
    printf("El valor cos(x0) si avaluem en precisió simple és %.16G.\n\n",cosx0);
    return 0;
}

/*Aquest codi s'ha creat per tal d'il·lustrar que el valor de cosf(x0) és idènticament 1 quan x0=0.000012, l'estructura d'aquest és idèntica a la dels anteriors codis*/