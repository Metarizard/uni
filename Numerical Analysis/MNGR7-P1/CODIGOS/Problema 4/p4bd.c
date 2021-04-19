#include<stdio.h>
#include<math.h>

int main (void){
  long int n,i;
  double sumatotal=0;
  printf("Fins a on vol sumar?\n");
  scanf("%li",&n);
  for(i=n;i>0;i--){
    sumatotal=sumatotal+1./i/i;
    }
    printf("La suma dels %li inversos dels naturals al quadrat en ordre DECREIXENT és %.16G\n",n,sumatotal);
  return 0;
}