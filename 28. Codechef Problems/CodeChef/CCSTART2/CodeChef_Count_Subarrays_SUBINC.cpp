#include <iostream>
using namespace std;

int main() {
   int a;
   cin>>a;
   
   for(int b=0;b<a;b++){
       int c;
       cin>>c;
       long int d[c];
       long int dp[c];
       for(int i=0;i<c;i++){
           cin>>d[i];
           dp[i]=1;
       }
      long long int ans=1;
       for(int i=(c-2);i>=0;i--){
           if(d[i]<=d[i+1]){
               dp[i]=dp[i]+dp[i+1];
               
           }
           ans=ans+dp[i];
       }
      
      cout<<ans<<endl;
      
      
      
   }
   
   
}
