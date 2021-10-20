// Left and right rotation

#include<iostream>
#include<vector>
using namespace std;


void  display(int A[],int s){
 for(int i=0;i<s;i++){
    cout<<A[i];
 }
}
// function Right_rotate 

int Right_rotate(int arr[], int s){       
   int arr2[s];          // temporary fucntion for storing last value so that we can shift records 
   arr2[0]=arr[s-1];   
               
   for(int i=s-1; i>0 ;i--){
     arr[i]=arr[i-1];
   }
   arr[0]=arr2[0];
}
int main(){

      int A[]={10,20,30,40,50,100};    // A array we are rotating
    
      int s =sizeof(A)/sizeof(A[0]); 
      
  Right_rotate(A,s);   // fuction for rotation
   display(A, s);      // show output

return 0;
}

