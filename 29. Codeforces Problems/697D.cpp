#include<bits/stdc++.h>
using namespace std;

long long _min(long long a,long long b)
{
    if(a>b)
        return a;

    return b;
}

void solve(vector<int>&a,vector<int>&b,int n,int m)
{
    long long res=0;
    for(int x:a)
        res+=x;

    if(res<m)
    {
        cout<<-1<<'\n';
        return ;
    }

    vector<int>one,two;
    for(int i=0;i<n;i++)
    {
        if(b[i]==1)
            one.push_back(a[i]);
        if(b[i]==2)
            two.push_back(a[i]);
    }

    sort(one.rbegin(),one.rend());
    sort(two.rbegin(),two.rend());

    long long sum1=0LL;
    long long sum2=accumulate(two.begin(),two.end(),0ll);
    int r=(int)two.size();
    int ans=INT_MAX;

    for(int l=0;l<=one.size();l++)
    {
        while(r>0 && sum1+sum2-two[r-1]>=m)
        {
            r--;
            sum2-=two[r];
        }

        if(sum1+sum2>=m)
        {
            ans=min(ans,l+(2*r));
        }

        if(l!=one.size())
        {
            sum1+=one[l];
        }
    }

    cout<<(ans==INT_MAX? -1 : ans)<<'\n';
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        solve(a,b,n,m);
    }
    return 0;
}