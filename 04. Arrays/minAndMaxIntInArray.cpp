#include <iostream>
void minMax(int [],int);
using namespace std;

int main()
{
   int a[6]={3,1,2,9,5,6};
   int size = sizeof(a)/sizeof(a[0]);
   minMax(a,size);
       return 0;
}
void minMax(int a[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(a[j]>a[j+1]){
                int temp;
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
    cout<<"\nMax : "<<a[size-1]<<"\n Min : "<<a[0]<<endl;
}
