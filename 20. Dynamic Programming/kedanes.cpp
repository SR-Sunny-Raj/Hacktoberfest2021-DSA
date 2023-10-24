#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
int sum=0,best=0;
for(int i=0;i<n;i++)
{
    sum=max(arr[i],sum+arr[i]);
    best=max(sum,best);
}
cout<<"maximum sum of contigious array is "<<best<<endl;
return 0;
}