#include<iostream>
#include<algorithm>
using namespace std;

void rotateby90(int n, int matrix[][n]) 
{
   for(int i=0;i<n,i++){
       for(int j=0;j<i;j++){
swap(matrix[i][j],matrix[j][i]);
       }
   } 

for(int i=0;i<(n/2);i++){
    for(int j=0;j<n;j++){
      swap(matrix[i][j],matrix[n-1-i][j]);  
    }
}



} 

int main(){
    int n=5;
int matrixa[][n]={1,2,3,4,5,6,7,8,9,0,4,5,6};
rotateby90(n,matrix[][n]) ;
}
