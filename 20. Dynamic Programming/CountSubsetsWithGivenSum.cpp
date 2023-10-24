#include<bits/stdc++.h>
using namespace std;

// Question
// Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

//This is a dp problem 

// Time Complexity: O(sum*n), where the sum is the ‘target sum’ and ‘n’ is the size of the array.

// Auxiliary Space: O(sum*n), as the size of the 2-D array, is sum*n. 

int totalSubsets(int a[],int n,int tar)
{
    // Initializing the matrix
    int dp[n + 1][tar + 1];
  // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= tar; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= tar; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=tar;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
 
 
    return dp[n][tar];


}


 
int main()
{
    int n,tar;
    cin>>n>>tar;

    int a[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    int val =totalSubsets(a,n,tar);
    cout<<"Total subsets are : "<<val<<"\n";


}