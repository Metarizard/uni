#include<stdio.h>
#include<math.h>

double fd(double);

int main (void){
    double x0;
    double fx0;
    printf("\nOn vol avaluar la funció?\n");
    printf("x0 = ");
    scanf("%lf",&(x0)); /*%lf indica que el nombre introduit es guardarà en precisió doble*/
    fx0=fd(x0);
    printf("El valor f(x0) si avaluem en precisió doble és %.16G.\n\n",fx0);
    return 0;
}

double fd(double x){
    if (x==0){
        return 0.5;
    }
    else{
        return (1-cos(x))/(x*x); /*La funció 'cos' tracta l'argument en precisió doble i retorna un valor en precisió doble també*/
    }
}

/*La descripció dels arguments és exactament idèntica a la del codi p1as.c*/