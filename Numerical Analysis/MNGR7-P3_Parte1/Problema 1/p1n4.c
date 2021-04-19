/* Problema 1 Pràctica 3, n=4*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926535897932384626433832795

double f(double d)/*Definició d'f(x)*/
{
  if((fabs(d)>=0.7)&&(fabs(d)<=1))
  {
    return -1;
  }
  else
  {
    return 1;
  }
}

int main (void)
{
  int i,j,n=4,np=180; /*n nombre nodes interpolació, np nombre de punts a representar una vegada obtingut el polinomi*/
  double *evalj; /*coordenades 'x' dels punts a representar*/
  double *fevalj; /*coordenades 'y' dels punts a representar amb la funció original*/
  double *xj; /*nodes xj=-1+j*2/(n-1)*/
  double *fj; /*imatge dels nodes*/
  double *poli; /*coordenades 'y' dels punts a representar amb el polinomi interpolador*/
  double **matriu; /*matriu que emmagatzema les diferències dividides*/

  xj=(double *)malloc(np*sizeof(double));/*Reserva de memòria*/
  fj=(double *)malloc(np*sizeof(double));
  matriu=(double **)malloc(n*sizeof(double));

  for(j=0;j<n;j++)
  {
    xj[j]=-1+j*2./(n-1);
    /*printf("\nx_%d = %.3G",j,xj[j]);*/
    fj[j]=f(xj[j]);
    matriu[j]=(double *)malloc(n*sizeof(double));
  }

  for(j=n;j<=np;j++)/*Assignem el mateix valor a tots els elements del vector per tal que no passin coses extranyes al plotar-los*/
  {
    xj[j]=1;
    fj[j]=-1;
  }

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      matriu[i][j]=0;/*Emmagatzem la matriu amb tot 0's per a que no estigui buida*/
    }
  }

 
  for(i=0;i<n;i++)
  {
      matriu[i][0]=fj[i];/*La primera columna són les imatges dels nodes*/
  }
  

  for(j=1;j<n;j++)/*Realitzem el mètode de Newton per a les diferències dividides (els coefs del polinomi interpolador queden a la primera fila)*/
  {
    for(i=0;i<n-j;i++)
    {
      matriu[i][j]=(matriu[i+1][j-1]-matriu[i][j-1])/(xj[j+i]-xj[i]);
    }
  }
  
  /*for(i=0;i<n;i++) OPCIONAL PRINT DE LA MATRIU
  {
    printf("\n");
    for(j=0;j<n;j++)
    {
      printf("%.3G\t",matriu[i][j]);
    }
  }*/


  poli=(double *)malloc(np*sizeof(double));
  evalj=(double *)malloc(np*sizeof(double));
  fevalj=(double *)malloc(np*sizeof(double));

  for(j=0;j<=np;j++)/*Assignació de valors als vectors*/
  {
    poli[j]=0;
    evalj[j]=-0.989+j*0.011;
    fevalj[j]=f(evalj[j]);
  }
  
  for(j=np;j>=0;j--)/*Càlcul dels valors que pren el polinomi interpolador mitjançant la regla de Horner*/
  {
    for(i=n-1;i>=0;i--)
    {
      poli[j]=poli[j]*(-fabs(evalj[j])-xj[i])+(matriu[0][i]);/*-fabs(evalj) degut que la funció és simètrica i es comporta millor a la part negativa*/
    }
  }
  
  for(j=0;j<=np;j++)
  {
      printf("\n%.8G\t%.8G\t%.8G\t%.8G\t%.8G",evalj[j],xj[j],poli[j],fj[j],fevalj[j]);/*sortida de dades per al posterior plot de les dades*/
  }

  free(xj);/*Alliberem memòria*/
  free(fj);
  free(poli);
  free(matriu);
  free(evalj);
  free(fevalj);

  return 0;
}