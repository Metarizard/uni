#include<stdio.h>
#include<math.h>
#include<time.h> /*Permet l'ús correcte del random number generator*/
#include<stdlib.h>

float var1s(float [],int);/*Declaració de les funcions que calculen la variança. 1-definició, 2-fórmula, s-simple, d-doble*/
float var2s(float [],int);
double var1d(double [],int);
double var2d(double [],int);

int main (void){
    int n;
    double gen;/*Nombre a partir del qual es generen les dades*/
    float varm1s;/*Variables dedicades a les variances amb la mateixa notació que a les funcions*/
    float varm2s;
    double varm1d;
    double varm2d;
    double uwu;/*Diferència entre gen i el nombre més gran que es vol tenir a la llista*/
    float *vs;/*Apuntadors que emmagatzemaran les dades en precisió simple i doble*/
    double *vd;
    int i;

    printf("Quantes dades vol avaluar?\n");
    scanf("%d",&n);
    printf("Al voltant de quin nombre estaran aquestes dades?\n");
    scanf("%lf",&gen);
    printf("Quant vol que distin les dades com a molt del nombre generador?\n");
    scanf("%lf",&uwu);
    
    vs=(float *)malloc(n*sizeof(float));
    vd=(double *)malloc(n*sizeof(double));

    srand(time(NULL));/*Generació de dades, és necessari inicialitzar cada vegada el timer del generador de nombres aleatoris*/
    for(i=0;i<n;i++){
        vd[i]=gen+uwu/100*(rand() %100);/*(rand() %100) retorna un enter entre 0 i 100. Llavors es guarden valors entre gen i gen+uwu amb variacions de 10^-2 respecte uwu*/
        vs[i]=(float) vd[i];/*Assignació de double a float del mateix nombre per tal que les llistes siguin idèntiques però en precisió diferent*/
    }
    
    varm1s=var1s(vs,n);/*Càlcul de les variances*/
    varm2s=var2s(vs,n);
    varm1d=var1d(vd,n);
    varm2d=var2d(vd,n);
    free(vs);/*Alliberem l'espai de memòria emprat*/
    free(vd);
    printf("\n (FLOAT) La variança de la mostra amb la primera fórmula és %.16G i amb la segona és %.16G\n",varm1s,varm2s);/*Mostra dels valors de la variança amb els 2 mètodes i les dues precisions en punt flotant*/
    printf("\n (DOUBLE)La variança de la mostra amb la primera fórmula és %.16G i amb la segona és %.16G\n",varm1d,varm2d);
    return 0;
}
    
float var1s(float vect[],int k){/*Les funcions són idèntiques a les dels programes p3as.c i p3ad.c*/
    int j;
    float suma=0;
    float mitj;
    float var=0;
    for (j=0;j<k;j++){
        suma=suma+vect[j];
    }
    mitj=suma/k;
    for (j=0;j<k;j++){
        var=var+(vect[j]-mitj)*(vect[j]-mitj);
    }
    return var/(k-1);
}

float var2s(float vect[],int k){
    int j;
    float suma=0;
    float sumaq=0;
    float var;
    for (j=0;j<k;j++){
        suma=suma+vect[j];
    }
    for (j=0;j<k;j++){
        sumaq=sumaq+vect[j]*vect[j];
    }
    var=sumaq-suma*suma/k;
    return var/(k-1);
}

double var1d(double vect[],int k){
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

double var2d(double vect[],int k){
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
