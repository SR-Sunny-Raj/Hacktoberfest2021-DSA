#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n" 
vector<string> all;
void permute(string a, int l, int r)  
{   
    if (l == r)  
        all.push_back(a);  
    else
    {   
        for (int i = l; i <= r; i++)  
        {  
   
            swap(a[l], a[i]);  
            permute(a, l+1, r);  
            swap(a[l], a[i]);  
        }  
    }  
}
int32_t main()
{
	IOS;
	int n,k;
	cin>>n>>k;
	int a[n+1][n+1];
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<n+1;j++)
			cin>>a[i][j];
	}
	string temp;
	int space;
	if(n==2)
	{
		if(a[1][2] + a[2][1] == k)
			cout<<"1";
		else
			cout<<"0";
	}
	if(n==3)
	{
		temp = "23";
		space = 2;
	}
	if(n==4)
	{
		temp = "234";
		space = 3;
	}
	if(n==5)
	{
		temp = "2345";
		space = 4;
	}
	if(n==6)
	{
		temp = "23456";
		space = 5;
	}
	if(n==7)
	{
		temp = "234567";
		space = 6;
	}
	if(n==8)
	{
		temp = "2345678";
		space = 7;
	}
	permute(temp,0 ,space-1) ;	
	for(auto it = all.begin();it != all.end(); it++)
	{
		*it = "1" + *it;
		*it = *it +"1";
	}
	int ans =0;
	for(auto it = all.begin();it != all.end(); it++)
	{
		int cost = 0;
		string str = *it;
		for(int i= 0;i<n ;i++)
		{
			cost +=  a[str[i] -'0'][str[i+1] - '0'];
		}
		if(cost==k)
			ans++;
		
	}
	cout<<ans;
	
	
	
	
		
	return 0;
}
