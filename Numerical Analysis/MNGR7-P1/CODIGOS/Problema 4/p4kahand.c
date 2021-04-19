#include<stdio.h>
#include<math.h>

/*mateix codi que p4kahans.c però en precisio doble*/

int main (void){
  long int n,i;
  double sumatotal=0;
  double e=0;
  double terme;
  double temp;
  printf("Fins a on vol sumar?\n");
  scanf("%li",&n);
  for(i=1;i<n+1;i++){
    temp=sumatotal;
    terme=1./i/i+e;
    sumatotal=temp+terme;
    e=(temp-sumatotal)+terme;
    }
    sumatotal=sumatotal+e;
    printf("La suma dels %li inversos dels naturals al quadrat es %.16G\n",n,sumatotal);
  return 0;
}