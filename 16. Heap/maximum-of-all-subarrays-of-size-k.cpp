#include<bits/stdc++.h>
using namespace std;

void Maximum_of_every_subarray(int a[],int n,int k)
{
    int i;
    deque<int> dq;
    
    for(i=0;i<k;i++)
    {
        while(!dq.empty() && a[i] > a[dq.back()])
        dq.pop_back();
        dq.push_back(i);
    }
    for(i=k;i<n;i++)
    {
        cout<<a[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= (i-k))
            dq.pop_front();
        
        while(!dq.empty() && a[i] > a[dq.back()])
        dq.pop_back();
        
        dq.push_back(i);
    }
    if(!dq.empty())
    cout<<a[dq.front()]<<" ";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n],i;
        for(i=0;i<n;i++)
        cin>>a[i];
        
        Maximum_of_every_subarray(a,n,k);
        cout<<endl;
    }
}
