#include <iostream>
using namespace std;

int main(){
    long int n,i,j;
    cout<<"Enter the no. of elements of the series required : ";
    cin>>n;
    long int catalan[n];
    catalan[0]=catalan[1]=1;
    cout<<catalan[0]<<" "<<catalan[1]<<" ";
    for(i=2;i<n;i++)
    {
        catalan[i]=0;
        
        for(j=0;j<i;j++)
        catalan[i]+=catalan[j]*catalan[i-j-1];
        
        cout<<catalan[i]<<" ";
    }
}