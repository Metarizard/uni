#include<stdio.h>
#include<math.h>

float gf(float f)/*Funció de la qual volem calcular una de les arrels*/
{
    return powf(f,3)-f-400;
}

double gd(double d)
{
    return pow(d,3)-d-400;
}

int main (void)
{
  float x;/*Variable que contindrà el valor de l'arrel*/
  double y;
  float errorx;/*Variable que emmagatzemarà el valor del segon sumand on es produeix la cancel·lació*/
  double errory;

  printf("\nDeterminarem per Bolzano que hi ha una solució a l'interval [2,8]:\n");/*Comprovació per Bolzano*/
  printf("g(2)*g(8)=%.8G\n",gf(2)*gf(8));
  if(gf(2)*gf(8)<0)/*Si es satisfà la condició computa l'arrel*/
  {
    printf("Com g(2)*g(8)<0 hi ha al menys una solució a l'interval [2,8].\n");

    x=cbrtf((400+sqrtf(powf(400,2)-4./27))/2)+cbrtf((400-sqrtf(powf(400,2)-4./27))/2);/*Càlcul arrel amb Cardano*/
    printf("\nEn precisió SIMPLE i la fórmula de Cardano, x = %.8G\n",x);
    printf("Avaluant el resultat obtenim g(x) = %.8G\n",gf(x));
    errorx=cbrtf((400-sqrtf(powf(400,2)-4./27))/2);
    printf("\nERRORx = %.8G\n",errorx);

    y=cbrt((400+sqrt(pow(400,2)-4./27))/2)+cbrt((400-sqrt(pow(400,2)-4./27))/2);
    printf("\nEn precisió DOBLE i la fórmula de Cardano, y = %.16G\n",y);
    printf("Avaluant el resultat obtenim g(y) = %.16G\n",gd(y));
    errory=cbrt((400-sqrt(pow(400,2)-4./27))/2);
    printf("\nERRORy = %.16G\n\n",errory);
  }
  else
  {
      printf("No podem assegurar l'existència de solucions a l'interval (2,8)\n\n");
  }
  return 0;
}