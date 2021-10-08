#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    string s1="LOVE";
    string s2="MOVIE";
    int n=s1.length();
    int m=s2.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
               if(i==0&&j==0){dp[i][j]=0;}
               else if(j==0)
               {
                   dp[i][j]=i;
               }
               else if(i==0)
               {
                      dp[i][j]=j;
               }
        }
    }
     

     for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]))+1;
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";

        }
        cout<<endl;
    } 

}