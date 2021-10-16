#include<bits/stdc++.h>
using namespace std;


int countsub(int a[],int n, int sum)
{
	if(n==0)
	return (sum==0)? 1:0;
	
	return countsub(a,n-1,sum)+countsub(a,n-1,sum-a[n-1]);
}
int main()
{
	int n;
	cin>>n;
	int a[n]={0};
	for(int i=0;i<n;i++)
	cin>>a[i];
	int sum;
	cin>>sum;
	cout<<countsub(a,n,sum)<<endl;
}
