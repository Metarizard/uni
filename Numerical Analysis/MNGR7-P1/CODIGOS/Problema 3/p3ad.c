#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/*Mateix codi que anteriorment (p3as.c) però en format de precisió doble*/
double var1(double [],int);
double var2(double [],int);

int main (void){
    int n;
    double varm1;
    double varm2;
    int i;
    double *v;

    printf("De quantes dades disposa?\n");
    scanf("%d",&n);
    
    v=(double *)malloc(n*sizeof(double));
    
    printf("Introdueixi les dades:\n");
    for(i=0;i<n;i++){
        printf("Dada %d = ",i+1);
        scanf("%lf",&(v[i]));
    }
    
    varm1=var1(v,n);
    varm2=var2(v,n);
    free(v);
    printf("\n (DOUBLE) La variança de la mostra amb la primera fórmula és %.16G i amb la segona és %.16G\n",varm1,varm2);
    
    return 0;
}
    
double var1(double vect[],int k){
    int j;
    double suma=0;
    double mitj;
    double var=0;
    for (j=0;j<k;j++){
        suma=suma+vect[j];
    }
    mitj=suma/k;
    for (j=0;j<k;j++){
        var=var+(vect[j]-mitj)*(vect[j]-mitj);
    }
    return var/(k-1);
}

double var2(double vect[],int k){
    int j;
    double suma=0;
    double sumaq=0;
    double var;
    for (j=0;j<k;j++){
        suma=suma+vect[j];
    }
    for (j=0;j<k;j++){
        sumaq=sumaq+vect[j]*vect[j];
    }
    var=sumaq-suma*suma/k;
    return var/(k-1);
}
