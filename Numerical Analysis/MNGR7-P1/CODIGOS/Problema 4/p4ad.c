#include<stdio.h>
#include<math.h>

/*Codi equivalent a p4as.c però en precisió doble*/

int main (void){
  long int n,i;
  double sumatotal=0;
  printf("Fins a on vol sumar?\n");
  scanf("%li",&n);
  for(i=1;i<n+1;i++){
    sumatotal=sumatotal+1./i/i;
    }
    printf("La suma dels %li inversos dels naturals al quadrat en ordre CREIXENT és %.16G\n",n,sumatotal);
  return 0;
}