#include<stdio.h>
#include<math.h>

int main (void){
  long int n,i;/*Probablement necessitem calcular la suma fins a ordres prou grans, requerint l'ús de long int*/
  float sumatotal=0;/*Variable destinada a emmagatzemar la suma dels termes*/
  printf("Fins a on vol sumar?\n");/*S'estableix el nombre de sumands per pantalla*/
  scanf("%li",&n);
  for(i=1;i<n+1;i++){/*Suma recursiva en ordre creixent de l'índex*/
    sumatotal=sumatotal+1./i/i;
    }
    printf("La suma dels %li inversos dels naturals al quadrat en ordre CREIXENT és %.16G\n",n,sumatotal);
  return 0;
}
  
      