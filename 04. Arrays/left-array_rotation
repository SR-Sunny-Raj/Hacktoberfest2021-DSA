#include <iostream>

using namespace std;


void l_rotate(int a[],int n){
    int i,k;
    k=a[0];
    for(i=0;i<n-1;i++){
        a[i]=a[i+1];
    }
    a[n-1]=k;
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
  
    l_rotate(a,n);
    cout<<"left rotation- \n";
    for(i=0;i<n;i++){
        cout<<a[i]<<' ';
    }

    return 0;
}
