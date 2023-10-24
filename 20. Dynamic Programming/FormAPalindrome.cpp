/*Given a string, find the minimum number of characters to be inserted to convert it to palindrome.
For Example:
ab: Number of insertions required is 1. bab or aba
aa: Number of insertions required is 0. aa
abcd: Number of insertions required is 3. dcbabcd*/

//Time complexity:-O(|S|^2)
//Space complexity:-O(|S|^2)
#include <bits/stdc++.h>
using namespace std;
int lcs(int x,int y,string s1,string s2){
      int t[x+1][y+1];
      for(int i=0;i<=x;i++){
          for(int j=0;j<=y;j++){
              if(i==0||j==0)
              t[i][j]=0;
          }
      }
      
      for(int i=1;i<=x;i++){
          for(int j=1;j<=y;j++){
              if(s1[i-1]==s2[j-1])
              t[i][j]=1+t[i-1][j-1];
              else{
                  t[i][j]=max(t[i-1][j],t[i][j-1]);
              }
          }
      }
      return t[x][y];
  }
    int findMinInsertions(string A){
        // code here 
        string B=A;
        reverse(B.begin(),B.end());
         int x=A.length();
        int ans= lcs(x,x,A,B);
        int res=abs(x-ans);
        return res;
    }
int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
       
        
        int ans=findMinInsertions(s);
        cout<<ans<<endl;
      
        
    }

    return 0;}
