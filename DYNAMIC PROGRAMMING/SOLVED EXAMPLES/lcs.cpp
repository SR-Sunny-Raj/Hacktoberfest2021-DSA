#include<bits/stdc++.h>
using namespace std;

int recur(string &a,string &b,int cura,int curb,vector<vector<int>>&dp)
{
	if(cura==a.size())
		return 0;
	if(curb == b.size())
		return 0;

	if(dp[cura][curb]!=-1)
		return dp[cura][curb];

	int ans = 0;
	if(a[cura]==b[curb])
		ans = recur(a,b,cura+1,curb+1,dp)+1;
	else
		ans = max(recur(a,b,cura,curb+1,dp),recur(a,b,cura+1,curb,dp));

	dp[cura][curb] = ans;
	return dp[cura][curb];
}

void ecur(string &a,string &b,int cura,int curb,vector<vector<int>>&pp)
{
	if(cura==a.size())
		return ;
	if(curb == b.size())
		return ;

	
	if(a[cura]==b[curb])
	{	cout<<a[cura];
		ecur(a,b,cura+1,curb+1,pp);
	}
	
	else
	{	
		
		int temp1 = pp[cura][curb+1];
		int temp2 = pp[cura+1][curb];
		if(temp1>temp2)
			ecur(a,b,cura,curb+1,pp);
		else
			ecur(a,b,cura+1,curb,pp);
	}

}

int main()
{
	string a,b;
	cin>>a>>b;
	std::vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,-1));
	recur(a,b,0,0,dp);
	ecur(a,b,0,0,dp);
	cout<<endl;
}