#include<stdio.h>
#include<math.h>
#define tol2 1.e-15
#define tol1 1.e-8

float newtonf(float f)/*Funcions que donat x_i retornen x_(i+1)=g(x_i) pel mètode de Newton*/
{
  return (f-(powf(f,3)-f-40)/(3*powf(f,2)-1));
}

double newtond(double d)
{
  return (d-(pow(d,3)-d-40)/(3*pow(d,2)-1));
}

int main (void)
{
  int k=1;/*Variable que guarda el nombre d'iteracions realitzades*/
  float x;/*Variable sobre la qual s'iterarà. La variable 'y' està destinada al mateix però en DOBLE precisió*/
  float xi=2;/*Inicialització x_i=x_0*/
  float ress;/*Variable que emmagatzema el valor on s'avaluaran els punts per comprovar si realment res=lim f(x_n)=0*/
  
  /*float terme;
  variable opcional si es vol apreciar el càlcul intern del mètode de Newton per als darrers termes. Explicat amb més detall posteriorment
  */

  double y;
  double yi=2;
  double resd;

  /*Càlcul en precisió simple*/
  printf("Calculant en precisió simple...\n");
  x=newtonf(xi);/*Assignació x=x_1*/
  printf("Iteració %d SIMPLE, valor x%d = %.8G\n",k,k,x);
  printf("|x%d - x%d| = %.8G\n",k-1,k,fabs(xi-x));
  while(fabsf(x-xi)>tol1)
  {
    xi=x;/*Realment aquí guardem el valor x_i que utilitzarem per comparar amb x_(i+1) posteriorment*/
    x=newtonf(xi);/*Càlcul x=x_(i+1)=g(x_i) mitjançant Newton*/
    k++;
    printf("Iteració %d SIMPLE, valor x%d = %.8G\n",k,k,x);
    printf("|x%d - x%d| = %.8G\n",k-1,k,fabs(xi-x));/*Sortida de la diferència en valor absolut de x_i-x_(i+1)*/ 
  }
  
  /*terme=(x*x*x-x-40)/(3*x*x-1);
  x=newtonf(x);
  printf("\nTerme restant: %.9G\n",terme);

  El codi superior serveix per a comprovar el valor del terme de la fórmula de Newton corresponent a f(x_i)/f'(x_i) que és 1.05622966E-07=0 en FLOAT
  amb la qual cosa és impossible determinar la solució amb més de 6 decimals correctes. Per tant no intentarem determinar-ne més.*/
  
  printf("\nEl resultat en precisió SIMPLE és\n");
  printf("%.8G\n",xi);
  ress=xi*xi*xi-xi-40;/*Retorna el valor x_i i no x_(i+1) ja que amb x_i ja s'han aconseguit els decimals correctes desitjats (en el cas FLOAT no però en DOUBLE sí que succeeix)*/
  printf("\nAvaluant el polinomi en dita solució x%d s'obté en SIMPLE:\n",k-1);
  printf("%.8G\n",ress);

  /*Càlcul en doble precisió 8 decimals*/
  k=1;
  printf("\n\nCalculant en precisió doble amb precisió de 8 decimals...\n");
  y=newtond(yi);
  printf("Iteració %d DOBLE, valor y%d = %.9G\n",k,k,y);
  printf("|y%d - y%d| = %.9G\n",k-1,k,fabs(yi-y));
  while(fabs(y-yi)>tol1)
  {
    yi=y;
    y=newtond(yi);
    k++;
    printf("Iteració %d DOUBLE, valor y%d = %.9G\n",k,k,y);
    printf("|y%d - y%d| = %.9G\n",k-1,k,fabs(yi-y));
  }
  printf("\nEl resultat en precisió DOBLE i precisió fins a 8 xifres decimals és\n");
  printf("%.9G\n",y);
  resd=yi*yi*yi-yi-40;
  printf("\nAvaluant el polinomi en dita solució y%d s'obté en DOBLE:\n",k-1);
  printf("%.9G\n",resd);

  /*Càlcul en doble precisió 15 decimals*/
  k=1;
  yi=2;
  printf("\n\nCalculant en precisió DOBLE amb precisió de 15 decimals...\n");
  y=newtond(yi);
  printf("Iteració %d DOBLE, valor y%d = %.16G\n",k,k,y);
  printf("|y%d - y%d| = %.16G\n",k-1,k,fabs(yi-y));
  while(fabs(y-yi)>tol2)
  {
    yi=y;
    y=newtond(yi);
    k++;
    printf("Iteració %d DOBLE, valor y%d = %.16G\n",k,k,y);
    printf("|y%d - y%d| = %.16G\n",k-1,k,fabs(yi-y));
  }
  printf("\nEl resultat en precisió DOBLE i precisió fins a 15 xifres decimals és\n");
  printf("%.16G\n",yi);
  resd=yi*yi*yi-yi-40;
  printf("\nAvaluant el polinomi en dita solució y%d s'obté en DOBLE:\n",k-1);
  printf("%.16G\n",resd);
  /*Si s'itera una vegada més s'obté l'iterat x_8. f(x_8) és idènticament 0 per a l'ordinador i per tant no aconseguiríem millorar el resultat en DOBLE*/ 
  return 0;
}
  
 
    
  