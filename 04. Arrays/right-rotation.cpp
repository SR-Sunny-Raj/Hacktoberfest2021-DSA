#include <iostream>

using namespace std;

void r_rotate(int a[],int n){
    int i,k;
    k=a[n-1];
    for(i=n-1;i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=k;
    
}
int main()
{
    int n,i;
    cout<<"Enter n "<<endl;
    cin>>n;
    int a[n];
    cout<<"enter array elements"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    r_rotate(a,n);
    cout<<"right rotation- \n";
    for(i=0;i<n;i++){
        cout<<a[i]<<' ';
    }


    return 0;
}
