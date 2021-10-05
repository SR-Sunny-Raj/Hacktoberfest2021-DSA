#include <bits/stdc++.h>
using namespace std;

void nbonacci(int a[],int N,int M)
{
    a[N-1]=1;
    for(int i=N;i<M;i++)
    {  int sum=0;
        for(int j=i-N;j<i;j++)
        {
            sum+=a[j];
        }   
        a[i]=sum;
        sum=0;
    }
    
}

int main()
{  
    int N,M;
    cout<<"enter N and M respectivily";
    cin>>N>>M;
    int a[M]={0};
    nbonacci(a,N,M);

    for(int i=0;i<M;i++)
    cout<<a[i]<<" ";

    return 0;
}