#include<stdio.h>
#include<math.h>

/*Codi equivalent a p4ds.c però en precisió doble*/

int main (void){
  long int n,m,i,j;
  long int ordre=10;
  int k=1;
  double suma[50];
  double terme;
  double sumatotal=0;
  for(j=0;j<50;j++){
    suma[j]=0;
  }
  suma[0]=1;
  printf("Fins a on vol sumar?\n");
  scanf("%li",&n);
  for(i=2;i<n+1;i++){
    terme=1./(i*i);
    if(terme>(1./ordre)){
      suma[k]=suma[k]+terme;
    }
    else{
      ordre=ordre*10;
      k=k+1;
      i=i-1;
    }
  }
  for(m=0;m<50;m++){
    sumatotal=sumatotal+suma[m];
  }
  printf("La suma dels %li inversos dels naturals al quadrat en PAQUETS és %.16G\n",n,sumatotal);
  return 0;
}