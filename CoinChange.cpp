/*
  
    Problem statement : You are given 3 coin of value 1, 3 and 4 in unlimited quantity you have 
                          to print minimum number coins needed to make sum of money.
                          
    Algorithm used : Dynamic programming
    
    
    Approach : We store value of coins minimum needed in an array and keep on adding the coins and compare the minimum no. of coin needed to 
                store for every particular element of coin till we reach to required sum.
               
*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    void initate(){
        int n;
        cin>>n;
        int d[n+1];
        for (int i = 0; i <= n; i++)
        {
            d[i]=-1;
        }
        d[0]=0;
        d[1]=1;
        d[2]=2;
        d[3]=1;
        d[4]=1;
        cout<<change(n,d)-1;
    }
    int change(int n,int d[]){
            if(d[n]!=-1){
                return d[n]+1;
            }
            d[n] = 1+min(change(n-1,d),min(change(n-3,d),change(n-4,d)));
            return d[n];
    }
};
int main(){
    solution s;
    s.initate();
}