#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.14159265358979323846

int main (void)
{
  float akf=1,bkf=1/sqrtf(2),ckf,skf=0.5,pkf,errkf,af,bf,sf,errf;/*Declaració de les variables i assignació de valors inicials*/
  double akd=1,bkd=1/sqrt(2),ckd,skd=0.5,pkd,errkd,ad,bd,sd,pd,ed,errd;
  long int kf=1,kd=1;/*Nombre iteracions*/

  pkf=2*akf*akf/skf;
  errkf=fabsf(PI-pkf);/*errkf emmagatzema l'error absolut entre p_k i p_(k+1)*/ 
  errf=100;/*Error prou gran per entrar a la primera iteració*/
  pkd=2*akd*akd/skd;
  errkd=fabs(PI-pkd);
  errd=100;

  /*Les següents instruccions ens ajudaran a determinar quina és la causa de la divergència a partir d'un cert índex*/
  while(errkf<errf)/*Les iteracions paren quan l'error absolut creix*/
  {
    af=akf;/*les variables acabades en 'f' emmagatzemen el terme k a l'inici de la iteració. Les variables acabades en 'kf' prenen el valor del terme k+1 de la iteració*/ 
    bf=bkf;
    sf=skf;
    errf=errkf;
    akf=(af+bf)/2;
    printf("a_%li f = %.8G\n",kf,akf);/*Sortida per pantalla del valor que pren cada terme involucrat en la iteració*/
    bkf=sqrtf(af*bf);
    printf("b_%li f = %.8G\n",kf,bkf);
    ckf=akf*akf-bkf*bkf;
    printf("c_%li f = %.8G\n",kf,ckf);
    skf=sf-pow(2,kf)*ckf;
    printf("s_%li f = %.8G\n",kf,skf);
    pkf=2*akf*akf/skf;
    errkf=fabsf(PI-pkf);
    kf++;
  }

  /*Inicialitzem un altre cop i calculem els iterats*/
  akf=1;
  bkf=1/sqrtf(2);
  skf=0.5;
  kf=1;
  pkf=2*akf*akf/skf;
  errkf=fabsf(PI-pkf);
  errf=100;
  while(errkf<errf)
  {
    af=akf;
    bf=bkf;
    sf=skf;
    errf=errkf;
    akf=(af+bf)/2;
    bkf=sqrtf(af*bf);
    ckf=akf*akf-bkf*bkf;
    skf=sf-pow(2,kf)*ckf;
    pkf=2*akf*akf/skf;
    errkf=fabsf(PI-pkf);
    printf("\nSIMPLE - Iteració %li, el terme p_%li és %.8G i l'error absolut és %.8G",kf,kf,pkf,errkf);/*Sortida per pantalla del terme p_k i l'error absolut |p_k-PI|*/
    kf++;
  }
  printf("\nSIMPLE - A la iteració %li l'error absolut creix de %.8G a %.8G\n",kf-1,errf,errkf);/*Missatge a mostrar quan l'error absolut creix, kf-1 degut que al final de la darrera iteració s'incrementa kf++*/

  /*Mateixes instruccions en DOBLE*/
  while(errkd<errd)
  {
    ad=akd;
    bd=bkd;
    sd=skd;
    errd=errkd;
    akd=(ad+bd)/2;
    bkd=sqrt(ad*bd);
    ckd=akd*akd-bkd*bkd;
    skd=sd-pow(2,kd)*ckd;
    pkd=2*akd*akd/skd;
    errkd=fabs(PI-pkd);
    printf("\nDOUBLE - Iteració %li, el terme p_%li és %.16G i l'error absolut és %.16G",kd,kd,pkd,errkd);
    kd++;
  }
  printf("\nDOUBLE - A la iteració %li l'error absolut creix de %.16G a %.16G\n",kd-1,errd,errkd);

  /*Determinació de l'ordre de convergència*/

  /*Ordre 1*/
  akd=1;
  bkd=1/sqrtf(2);
  skd=0.5;
  kd=1;
  pkd=2*akd*akd/skd;
  pd=1;
  errkd=fabsf(PI-pkd);
  errd=100;
  printf("\nConvergència ordre 1?");
  while(errkd<errd)
  {
    ed=fabs(pkd-pd);
    pd=pkd;
    ad=akd;
    bd=bkd;
    sd=skd;
    pd=pkd;
    errd=errkd;
    akd=(ad+bd)/2;
    bkd=sqrt(ad*bd);
    ckd=akd*akd-bkd*bkd;
    skd=sd-pow(2,kd)*ckd;
    pkd=2*akd*akd/skd;
    errkd=fabs(PI-pkd);
    printf("\nDOUBLE - Iteració %li, |p_%li-p_%li|/|p_%li-p_%li| = %.16G",kd-1,kd,kd-1,kd-1,kd-2,(fabs(pkd-pd))/ed);
    kd++;
  }

  /*Ordre 2*/
  akd=1;
  bkd=1/sqrtf(2);
  skd=0.5;
  kd=1;
  pkd=2*akd*akd/skd;
  pd=1;
  errkd=fabsf(PI-pkd);
  errd=100;
  printf("\nConvergència ordre 2?");
  while(errkd<errd)
  {
    ed=fabs(pkd-pd);
    pd=pkd;
    ad=akd;
    bd=bkd;
    sd=skd;
    errd=errkd;
    akd=(ad+bd)/2;
    bkd=sqrt(ad*bd);
    ckd=akd*akd-bkd*bkd;
    skd=sd-pow(2,kd)*ckd;
    pkd=2*akd*akd/skd;
    errkd=fabs(PI-pkd);
    printf("\nDOUBLE - Iteració %li, |p_%li-p_%li|/|p_%li-p_%li|^2 = %.16G",kd-1,kd,kd-1,kd-1,kd-2,fabs(pkd-pd)/pow(ed,2));
    kd++;
  }

  /*Ordre 3*/
  akd=1;
  bkd=1/sqrtf(2);
  skd=0.5;
  kd=1;
  pkd=2*akd*akd/skd;
  pd=1;
  errkd=fabsf(PI-pkd);
  errd=100;
  printf("\nConvergència ordre 3?");
  while(errkd<errd)
  {
    ed=fabs(pkd-pd);
    pd=pkd;
    ad=akd;
    bd=bkd;
    sd=skd;
    errd=errkd;
    akd=(ad+bd)/2;
    bkd=sqrt(ad*bd);
    ckd=akd*akd-bkd*bkd;
    skd=sd-pow(2,kd)*ckd;
    pkd=2*akd*akd/skd;
    errkd=fabs(PI-pkd);
    printf("\nDOUBLE - Iteració %li, |p_%li-p_%li|/|p_%li-p_%li|^3 = %.16G",kd-1,kd,kd-1,kd-1,kd-2,fabs(pkd-pd)/pow(ed,3));
    kd++;
  }
  return 0;
}

