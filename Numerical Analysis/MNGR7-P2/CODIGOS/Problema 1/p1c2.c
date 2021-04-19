#include<stdio.h>
#include<math.h>
#define tol 1.e-15

/*Codi equivalent a p1c1 però amb el mètode de la secant*/ 
double gd(double d)
{
    return pow(d,3)-d-400;
}

double *sec(double esq,double dre)
{
  int i=0;
  static double resultat[2];
  double x=esq;
  double y=dre;
  double z;
  while(fabs(x-y)>tol)
  {
    z=x;/*z=x_i*/
    x=y;/*x=x_(i+1)*/
    y=(z*gd(y)-y*gd(z))/(gd(y)-gd(z));/*Càlcul de y=x_(i+2), recordem que x_(i+2) depèn d'x_i i x_(i+1)*/
    printf("\n|x_%d-x_%d|/|x_%d-x_%d|^(1.6) = %.16G\n",i+2,i+1,i+1,i,fabs((y-x)/pow(x-z,1.6)));
    i++;
  }
  resultat[0]=y;
  resultat[1]=i;
  return resultat;
}

int main(void)
{
    double e=2;
    double d=8;
    double *resul;
    resul=sec(e,d);
    printf("\nSECANT - L'arrel es troba al punt x = %.16G amb %.3G iteracions\n",resul[0],resul[1]);
    printf("El valor de  g(x) és doncs g(x) = %.16G\n",gd(resul[0]));
    return 0;
}