#include<stdio.h>
#include<math.h>
#include<stdlib.h> /*Permet l'ús de la funció malloc sense restriccions*/

float var1(float [],int);/*Declaració de les funcions que calculen la variança donat un vector de n components*/
float var2(float [],int);/*var1 calcula la variança amb la definició i var2 calcula la variança amb la fórmula alternativa*/

int main (void){
    int n;/*Enter que determina la quantitat de dades que volem avaluar*/
    float varm1;/*Variables on s'emmagatzemaran les variances de la definició (varm1) i de la fórmula alternativa (varm2)*/ 
    float varm2;
    int i;/*Enter per al bucle*/
    float *v;/*Apuntador que servirà per emmagatzemar les dades en un vector n dimensional*/
    
    printf("De quantes dades disposa?\n");
    scanf("%d",&n);/*Pas per pantalla del nombre de dades a avaluar*/
    
    v=(float *)malloc(n*sizeof(float));/*Assignació dinàmica de memòria, reserva la memòria suficient per emmagatzemar n nombres en format float*/

    printf("Introdueixi les dades:\n");
    for(i=0;i<n;i++){
        printf("Dada %d = ",i+1);/*Introducció de les dades per pantalla i posterior assignació al lloc v[i] del vector*/
        scanf("%f",&(v[i]));
    }
    
    varm1=var1(v,n);/*Càlcul pròpiament dit de la variança una vegada emmagatzemat el vector i la seva dimensió*/
    varm2=var2(v,n);
    free(v);/*Alliberem la memòria que teníem reservada*/
    printf("\n (FLOAT) La variança de la mostra amb la primera fórmula és %.8G i amb la segona és %.8G\n",varm1,varm2);
    
    return 0;
}
    
float var1(float vect[],int k){/*Definició de les funcions que calculen la variança*/
    int j;/*Enter per al bucle, serà l'índex que es mourà 1 a 1 entre les components del vector introduït*/
    float suma=0;/*suma emmagatzemarà la suma de totes les components del vector*/
    float mitj;/*variable destinada a contenir el valor de la mitjana de les dades*/
    float var=0;/*variable que emmagatzema el valor de la variança*/
    for (j=0;j<k;j++){/*Càlcul de la suma recursiva*/
        suma=suma+vect[j];
    }
    mitj=suma/k;/*Assignació del valor de la mitjana per definició*/
    for (j=0;j<k;j++){/*Càlcul del sumatiori de la variança amb la suma recursiva pròpia de la definició*/
        var=var+(vect[j]-mitj)*(vect[j]-mitj);
    }
    return var/(k-1);/*La variança és el sumatori entre el nombre total de dades menys 1*/
}

float var2(float vect[],int k){/*Mateix procés però el càlcul és diferent*/
    int j;
    float suma=0;/*Terme del primer sumatori*/
    float sumaq=0;/*Terme del segon sumatori*/
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
