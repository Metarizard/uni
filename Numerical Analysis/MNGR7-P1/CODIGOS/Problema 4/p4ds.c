#include<stdio.h>
#include<math.h>

/*Es guardaran sumands depenent del seu ordre de magnitud*/

int main (void){
  long int n,m,i,j;
  long int ordre=10; /*Establim l'ordre de magnitud en base decimal*/
  int k=1;/*Primer ordre*/
  float suma[30];/*suma[j] emmagatzema la suma dels termes d'ordre 10^(-j)*/
  float terme;
  float sumatotal=0;
  for(j=0;j<30;j++){/*Els termes on no hi arribi el càlcul són 0 per defecte*/
    suma[j]=0;
  }
  suma[0]=1;/*Lúnic terme d'ordre 10^0 és el primer*/ 
  printf("Fins a on vol sumar?\n");
  scanf("%li",&n);/*S'estableix quants nombres es volen sumar*/
  for(i=2;i<n+1;i++){
    terme=1./(i*i);/*Assignació del terme i-èssim de la suma*/
    if(terme>(1./ordre)){/*Suma recursiva dels termes d'ordre 10^(-k) corresponents*/ 
      suma[k]=suma[k]+terme;
    }
    else{
      ordre=ordre*10;/*Passem a l'ordre de magnitud següent (més petit perquè despres dividim)*/
      k=k+1;/*Sumem 1 a k per tal de passar a la següent posició del vector suma i emmagatzemar un nou ordre de magnitud*/
      i=i-1;/*Si s'ha arribat aquí, el terme i-èssim no s'ha amagat en cap suma[k], per tant com en soritr d'else tornem a entrar al for (cosa que suposa i++), hem de fer i=i-1 per tenir en compte aquest terme*/
    }
  }
  for(m=0;m<30;m++){
    sumatotal=sumatotal+suma[m];/*sumem tots els paquets*/
  }
  printf("La suma dels %li inversos dels naturals al quadrat en PAQUETS és %.16G\n",n,sumatotal);
  return 0;
}
  
      