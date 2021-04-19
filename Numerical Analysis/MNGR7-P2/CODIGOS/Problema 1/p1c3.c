#include<stdio.h>
#include<math.h>
#define tol 1.e-15

/*Codi semblant als anteriors, no s'introdueix cap comanda ni funció noves*/
double gd(double d)
{
    return pow(d,3)-d-400;
}

double newtond(double d)
{
  return (d-(pow(d,3)-d-400)/(3*pow(d,2)-1));
}


int main(void)
{
    double x=2;/*Llavor inicial*/
    double xi=newtond(x);
    double y=newtond(xi);
    int i=1;
    printf("\n|x_2-x_1|/|x_1-x_0|^2 = %.16G\n",fabs((y-xi)/pow(xi-x,2)));
    while(fabs(x-xi)>tol)
    {
      x=xi;
      xi=newtond(xi);
      y=newtond(xi);
      printf("\n|x_%d-x_%d|/|x_%d-x_%d|^2 = %.16G\n",i+2,i+1,i+1,i,fabs((y-xi)/pow(xi-x,2)));
      i++;
    }
    printf("\nNEWTON - L'arrel es troba al punt x = %.16G amb %d iteracions\n",xi,i);
    printf("El valor de  g(x) és doncs g(x) = %.16G\n",gd(xi));
    return 0;
}