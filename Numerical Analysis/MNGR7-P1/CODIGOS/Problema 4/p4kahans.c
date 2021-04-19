#include<stdio.h>
#include<math.h>

int main (void){
  long int n,i;
  float sumatotal=0;
  float e=0;/*variable que emmagatzema l'error comès a cada suma 'recursiva'*/
  float terme;
  float temp;/*suma temporal*/
  printf("Fins a on vol sumar?\n");
  scanf("%li",&n);
  for(i=1;i<n+1;i++){
    temp=sumatotal;/*temp adquereix el valor de suma temporalment*/
    terme=1./i/i+e;/*afegim l'error comès a l'anterior loop al nou terme*/ 
    sumatotal=temp+terme;/*suma recursiva*/
    e=(temp-sumatotal)+terme;/*l'ordre de les operacions és clau per determinar l'error, les xifres significatives que s'han perdut en sumar el terme petit a la suma*/
    }
    sumatotal=sumatotal+e;/*afegim tots els errors (xifres que s'haurien perdut per falta de precisió en la mantissa)*/
    printf("La suma dels %li inversos dels naturals al quadrat es %.16G\n",n,sumatotal);
  return 0;
}