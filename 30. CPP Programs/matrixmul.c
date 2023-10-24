#include<stdio.h>
#include <stdlib.h>
void read_matrix(int a[][100],int m,int n){
 
  printf("Enter Elements : ");
  for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
    scanf("%d",&a[i][j]);
  }
}
void displaymatrix(int a[][100],int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
    printf("%d\t",a[i][j]);
  printf("\n");
 }
}
void addmatrix(int a[][100],int b[][100],int m,int n)
{
 int i,j,c[100][100];
 for(i=0;i<m;i++)
   for(j=0;j<n;j++)
    c[i][j]=a[i][j]+b[i][j];
 printf("Sum of matrix...\n");
 
 displaymatrix(c,m,n);
}
void multmatrix(int a[][100],int b[][100],int m1,int n1,int n2)
{
 int c[100][100],i,j,k;

    for (i = 0; i < m1; i++) {
        for (j = 0; j < n2; j++) {
            c[i][j] = 0;
            for (k = 0; k < n1; k++)
                c[i][j] += a[i][k] * b[k][j];
        }
    }
 printf("Product of matrix...\n");
 displaymatrix(c,m1,n2);
}
void transpose(int a[][100],int m,int n)
{
 int i,j,c[100][100];
 for(i=0;i<m;i++)
   for(j=0;j<n;j++)
    c[j][i]=a[i][j];

 displaymatrix(c,n,m);
}

int main(){
  int choice,m1,n1,m2,n2;
  int a[100][100],b[100][100],c[100][100];
  while (1){
  printf("\n1.Read Matrix");
  printf("\n2.Sum of Matrix");
  printf("\n3.Multiplication of Matrix");
  printf("\n4.Transpose of Matrix");
  printf("\n5.Exit");
  printf("\nEnter your choice:");
  scanf("%d",&choice);
  
  switch(choice){
    case 1:
      printf("\nEnter limits of Array 1 :");
      scanf("%d %d",&m1,&n1);
      read_matrix(a,m1,n1);
      printf("\nEnter limits of Array 2 :");
      scanf("%d %d",&m2,&n2);
      read_matrix(b,m2,n2);
      break;
    case 2:
        if(m1==m2 && n1==n2)
          addmatrix(a,b,m1,n1);
        else
          printf("\nAddition is not possible");          
        break;
    case 3:
        if(n1==m2)
                  multmatrix(a,b,m1,n1,n2);
        else
                   printf("\nMultiplication is not possible");
        break;

    case 4: 
        printf("Transpose of A..\n");
                transpose(a,m1,n1);
                printf("Transpose of B..\n");
                transpose(b,m2,n2);
          break;
    case 5:exit(0);

    default:
    printf("Wrong choice");
   }
  
  }
  return 0;
 }
