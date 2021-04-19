#include<stdio.h>
#include<math.h>

double sol1(double,double,double);
double sol2(double,double,double);

int main(void){
  double a;
  double b;
  double c;
  double x1;
  double x2;
  printf("\nEstableixi els coeficients a,b,c de ax^2+bx+c=0 :");
  printf("\na = ");
  scanf("%lf",&a);
  printf("\nb = ");
  scanf("%lf",&b);
  printf("\nc = ");
  scanf("%lf",&c);
  if(b*b>4*a*c){
    x1=sol1(a,b,c);
    x2=sol2(a,b,c);
    printf("\nLes solucions són x1 = %.16G i x2 = %.16G\n",x1,x2);
  }
  else{
    printf("\nNo es compleix que b^2>4ac o a>0!\n");
  }
  return 0;
}

double sol1(double c1,double c2, double c3){
  double res;
  if(c2>0){
    res=-2.*c3/(c2+sqrt(c2*c2-4*c1*c3)); 
  }
  else{
    res=(-c2+sqrt(c2*c2-4*c1*c3))/(2.*c1);
  }
  return res;
}

double sol2(double c1,double c2, double c3){
  double res;
  if(c2<0){
    res=2.*c3/(-c2+sqrt(c2*c2-4*c1*c3)); 
  }
  else{
    res=(-c2-sqrt(c2*c2-4*c1*c3))/(2.*c1);
  }
  return res;
}