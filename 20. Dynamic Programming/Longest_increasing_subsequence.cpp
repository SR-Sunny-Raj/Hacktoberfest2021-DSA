// Longest Increasing Subsequence
#include<iostream>
using namespace std;
int lis(int* a,int n)
{
    int* output=new int[n];
    output[0]=1;
    for(int i=1;i<n;i++)
    {
        output[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(a[j]<a[i] && output[i]<output[j]+1)
            {
                output[i]=output[j]+1;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(ans<output[i])
        {
            ans=output[i];
        }
    }
    return ans;
    
}
int main()
{
    int size;
    cin>>size;
    int* arr=new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    cout<<lis(arr,size);
    return 0;
}