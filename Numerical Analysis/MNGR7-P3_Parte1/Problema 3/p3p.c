/* Problema 3 Pràctica 3, interp. positius */ 

#include<stdio.h> 
#include<math.h> 
#include<stdlib.h> 
#define PI 3.1415926535897932384626433832795 
 
int main (void) 
{ 
  int i,j,n1=2,n3=4,n5=6,np=180;/*Mateix codi però amb 3 polinomis interpoladors*/
  double *xj;
  double *fj; 
  double *evalj; 
  double *poli1;    
  double *poli3;
  double *poli5;    
  double **matriu1;  
  double **matriu3;
  double **matriu5;
 
  xj=(double *)malloc(np*sizeof(double)); 
  fj=(double *)malloc(np*sizeof(double)); 
  matriu1=(double **)malloc(n1*sizeof(double));
  matriu3=(double **)malloc(n3*sizeof(double));
  matriu5=(double **)malloc(n5*sizeof(double));  
  
  for(j=0;j<=np;j++) 
  { 
    xj[j]=0.281818559374385; 
    fj[j]=1.9;
  } 
  
  xj[5]=0.281818559374385;
  xj[4]=0.223890779141236;
  xj[3]=0.166606980331990;
  xj[2]=0.110362266922174;
  xj[1]=0.055539784445602;
  xj[0]=0.002507683297244;
  
  for(j=0;j<=5;j++)
  {
      fj[j]=2.4-0.1*j;
  }
  
  
  for(j=0;j<n1;j++) 
  {
    matriu1[j]=(double *)malloc(n1*sizeof(double));
  } 


  for(j=0;j<n3;j++) 
  { 
    matriu3[j]=(double *)malloc(n3*sizeof(double));
  } 
  
  for(j=0;j<n5;j++) 
  { 
    matriu5[j]=(double *)malloc(n5*sizeof(double));
  } 
 
  for(i=0;i<n1;i++) 
  { 
    for(j=0;j<n1;j++) 
    { 
      matriu1[i][j]=0;
    } 
  } 
 
  for(i=0;i<n3;i++) 
  { 
    for(j=0;j<n3;j++) 
    { 
      matriu3[i][j]=0;
    } 
  } 
  
  for(i=0;i<n5;i++) 
  { 
    for(j=0;j<n5;j++) 
    { 
      matriu5[i][j]=0;
    } 
  }

  for(i=0;i<n1;i++) 
  { 
      matriu1[i][0]=fj[i]; 
  }
  
  for(i=0;i<n3;i++) 
  { 
      matriu3[i][0]=fj[i]; 
  }

  for(i=0;i<n5;i++) 
  { 
      matriu5[i][0]=fj[i]; 
  }
   
  for(j=1;j<n1;j++) 
  { 
    for(i=0;i<n1-j;i++) 
    { 
      matriu1[i][j]=(matriu1[i+1][j-1]-matriu1[i][j-1])/(xj[j+i]-xj[i]); 
    } 
  } 
  
  for(j=1;j<n3;j++) 
  { 
    for(i=0;i<n3-j;i++) 
    { 
      matriu3[i][j]=(matriu3[i+1][j-1]-matriu3[i][j-1])/(xj[j+i]-xj[i]); 
    }
  } 
  
   for(j=1;j<n5;j++) 
  { 
    for(i=0;i<n5-j;i++) 
    { 
      matriu5[i][j]=(matriu5[i+1][j-1]-matriu5[i][j-1])/(xj[j+i]-xj[i]); 
    }
  } 

  poli1=(double *)malloc(np*sizeof(double)); 
  poli3=(double *)malloc(np*sizeof(double)); 
  poli5=(double *)malloc(np*sizeof(double)); 
  evalj=(double *)malloc(np*sizeof(double)); 
  
  for(j=0;j<=np;j++) 
  { 
    poli1[j]=0;
    poli3[j]=0;
    poli5[j]=0;
    evalj[j]=-0.005+j*0.01/np;
  } 
   
  for(j=np-1;j>=0;j--) 
  { 
    for(i=n1-1;i>=0;i--) 
    { 
      poli1[j]=poli1[j]*(evalj[j]-xj[i])+(matriu1[0][i]); 
    } 
  } 

  for(j=np-1;j>=0;j--) 
  { 
    for(i=n3-1;i>=0;i--) 
    { 
      poli3[j]=poli3[j]*(evalj[j]-xj[i])+(matriu3[0][i]); 
    } 
  }
  
  for(j=np-1;j>=0;j--) 
  { 
    for(i=n5-1;i>=0;i--) 
    { 
      poli5[j]=poli5[j]*(evalj[j]-xj[i])+(matriu5[0][i]); 
    } 
  }

  printf("\n%.8G\t%.8G\t%.8G",poli1[90],poli3[90],poli5[90]); /*Avaluant a evalj[90] estem avaluant en 0*/

  free(xj); 
  free(fj);
  free(evalj);
  free(poli1); 
  free(poli3); 
  free(poli5); 
  free(matriu1); 
  free(matriu3);
  free(matriu5);
 
  return 0; 
}