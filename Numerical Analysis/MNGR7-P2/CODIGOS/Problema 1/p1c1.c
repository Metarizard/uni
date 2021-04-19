#include<stdio.h>
#include<math.h>
#define tol 1.e-15/*Assegurem 15 xifres decimals correctes*/

double gd(double d)/*Funció g(x)*/
{
    return pow(d,3)-d-400;
}

double *bi(double esq,double dre)/*Funció bisecció que retorna un apuntador a un vector de dues components amb el resultat i el nombre d'iteracions*/
{
  int i=0;
  double pi;/*Variable sobre la qual s'itera*/
  double p1,p2;/*p1 guardarà el valor x_i, p2 guardarà el valor d'x_(i+2) per a poder determinar l'ordre de convergència*/
  static double resultat[2];/*Static perquè volem recuperar el vlor que pren fora de la funció*/
  double esqi=esq;/*Iterats de l'interval*/
  double drei=dre;
  while(fabs(dre-esq)/pow(2,i)>tol)/*Mètode de la bisecció fins que la fita de l'error sigui menor a 'tol*/
  {
    p1=pi;
    pi=(esqi+drei)/2;
    if(gd(esqi)*gd(pi)<=0)
    {
      esqi=esqi;
      drei=pi;
    }
    else
    {
      esqi=pi;
      drei=drei;
    }
    p2=(esqi+drei)/2;
    printf("\n|x_%d-x_%d|/|x_%d-x_%d| = %.16G\n",i+2,i+1,i+1,i,fabs((p2-pi)/pow(pi-p1,1)));/*Comprovació de l'ordre*/
    i++;
  }
  resultat[0]=pi;
  resultat[1]=i;
  return resultat;
}

int main(void)
{
    double e=2;/*Valor dels extrems de l'interval*/
    double d=8;
    double *resul;
    resul=bi(e,d);
    printf("\nBISECCIÓ - L'arrel es troba al punt x = %.16G amb %.3G iteracions\n",resul[0],resul[1]);
    printf("El valor de  g(x) és doncs g(x) = %.16G\n",gd(resul[0]));
    return 0;
}