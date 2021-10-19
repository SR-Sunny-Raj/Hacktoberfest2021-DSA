#include<bits/stdc++.h>
using namespace std;

void dupli(int arr[],int n)
{
    int a=10;
    int arr2[a];
    
    for(int i=0;i<a;i++)
    {
        arr2[i]=0;
    }
    
    for(int i=0;i<n;i++)
    {
        arr2[arr[i]]++;
    }
    
    cout<<"Duplicate elements are :"<<"\n";
    for(int i=0;i<a;i++)
    {
       if(arr2[i]>=2)
       {
           cout<<i<<": "<<"Occurence of 2 :"<<arr2[i]<<" times";
           cout<<"\n";
       }
    }
}


int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter array elements :\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
     dupli(arr,n);
    return 0;
}