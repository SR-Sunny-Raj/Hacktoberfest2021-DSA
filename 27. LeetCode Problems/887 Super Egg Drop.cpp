class Solution {
public:
    int dp[10001][101];
    int sol(int k,int n){
        if(k==1||n==1) return n;
        if(dp[n][k]!=-1) return dp[n][k];
        
        int ans=n,l=1,h=n;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int left=sol(k-1,mid-1);   //egg broken check for down floors of mid
            int right=sol(k,n-mid) ;   // not broken check for up floors of mid
            int temp=1+max(left,right);          //store max of both 
            if(left<right){                  //since right is more than left and we need more in wrost case
              l=mid+1;                       // so l=mid+1 to gain more temp for worst case: upward
            }
            else                             //left > right so we will go downward 
            {    
                h=mid-1;
            }
            ans=min(ans,temp);               //store minimum attempts
        }
        
        return dp[n][k]=ans;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof dp);
        return sol(k,n);
    }
};
