#include<stdio.h>
#include<math.h>

double fd(double);

int main (void){
    double x0;
    double fx0;
    printf("\nOn vol avaluar la funció?\n");
    printf("x0 = ");
    scanf("%lf",&(x0));
    fx0=fd(x0);
    printf("El valor f(x0) si avaluem en precisió doble és %.16G.\n\n",fx0);
    return 0;
}

double fd(double x){
    if (x==0){
        return 0.5;
    }
    else{
        return 2*sin(x/2)*sin(x/2)/(x*x);
    }
}

/*Comentaris idèntics als dels codis anteriors p1as.c, p1ad.c, p1bs.c*/