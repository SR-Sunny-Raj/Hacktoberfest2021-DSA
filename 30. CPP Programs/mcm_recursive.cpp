//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = long long int;
int dp[102][102];

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int solve(vector<int>& vec,int i, int j){
	if(i>=j){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int minval=INT_MAX;
	for(int k=i;k<=j-1;k++){
		int temp=solve(vec,i,k) + solve(vec,k+1,j) + (vec[i-1] * vec[k] * vec[j]);
		minval=min(minval,temp);
	}
	return dp[i][j]=minval;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    jets();
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	vector<int> vec(n);
    	memset(dp,-1,sizeof dp);
    	for(int i=0;i<n;i++){
    		cin>>vec[i];
    	}
    	cout<<solve(vec,1,n-1)<<endl;
    }


    return 0;
}