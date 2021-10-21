#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n,m;
	cin>>n>>m;
	ll kmin,kmax,x;
	if(m==1)
	{
		kmin=n*(n-1)/2;
		kmax=kmin;
	}
	else
	{
		kmin=(n%m)*(n/m)*((n/m)+1)/2+(m-n%m)*(n/m)*((n/m)-1)/2;
		x=n-m+1;
		kmax=(x)*(x-1)/2;
	}
	cout<<kmin<<" "<<kmax;
}
