#include <bits/stdc++.h>
using namespace std ;

int main ()
{
  const int size =20; int l=1;
  cout<<"SPARSE MATRIX"<<endl;
  int A[size][size],B[size][3], R , C,Z,nz;
  cout<<"Enter the no. Rows in  the matrix   :";
  cin>> R;
  cout<<"Enter the no. columns in  the matrix    :";
  cin>> C;
  for(int i=0 ;i<R;i++)
  for(int j=0 ;j<C;j++)
  {
    cout<<"Enter Element A["<<i+1<<"]["<<j+1<<"]   :";
    cin>>A[i][j];
    if(A[i][j]==0) Z++;
    else nz++;
  }
  if(Z>((R*C)/2))
  {    B[0][0]= R;
       B[0][1]= C;
       B[0][2]= nz;
    for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
    if(A[i][j]!=0)
      {
      	B[l][0]= i;
      	B[l][1]= j;
      	B[l][2]= A[i][j];
      l++;
      }
  }
     cout<<"The Sparse matrix is given by    :\n";
     for(int i=0;i<l;i++)
     {
      for(int j=0;j<3;j++)
       cout<<B[i][j]<<"   ";
       cout<<endl;
     }
  
  return 0;
}


