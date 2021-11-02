/* CODECHEF PROBLEM STATEMENT LINK- https://www.codechef.com/SEPT21C/problems/AIRLINE */

#include<bits/stdc++.h>
using namespace std;
int main()
{   int t;              //test cases
    cin>>t;
    int a,b,c,d,e;      
    
    while(t--){
        cin>>a>>b>>c>>d>>e;
        if(((a+b)<=d && c<=e)||((b+c)<=d && a<=e)||((c+a)<=d && b<=e))      //checking the conditions
        cout<<"YES\n";
        else 
        cout<<"NO\n";
    }
    
    
    return 0;
}
