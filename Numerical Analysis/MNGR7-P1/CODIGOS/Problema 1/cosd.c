#include<stdio.h>
#include<math.h>

int main (void){
    double x0;
    double cosx0;
    printf("\nOn vol avaluar la funció cos(x)?\n");
    printf("x0 = ");
    scanf("%lf",&(x0));
    cosx0=cos(x0);
    printf("El valor cos(x0) si avaluem en precisió doble és %.16G.\n\n",cosx0);
    return 0;
}