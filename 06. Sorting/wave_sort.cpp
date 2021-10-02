
#include<iostream>
using namespace std;
int main(){

    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);

    ///Go to every 2nd element, try to create a peak
    for(int i=0;i<n;i+=2){

        ///Check for Left Element
        if(i>0 && a[i-1]>a[i]){
            swap(a[i],a[i-1]);
        }
        ///Check for the right element
        if(i<=n-2 && a[i+1]>a[i]){
            swap(a[i],a[i+1]);
        }

    }
    ///Print the array
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

return 0;
}