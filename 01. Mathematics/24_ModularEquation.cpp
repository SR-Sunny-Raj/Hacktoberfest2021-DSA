//Problem Code: MODEQ

/*
Given integers N and M, find the number of ordered pairs (a,b) such that 1≤a<b≤N and ((M mod a) mod b)=((M mod b) mod a).
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
The only line of each test case contains two integers N, M.
Output
For each testcase, output in a single line the answer to the problem.
*/


#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void fast_io()
{   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast_io();
    ll T;
    cin>>T;
    while(T--)
    {
        ll M,N;
        cin>>N>>M;
        ll count=0;
        vector<long long> mod(N+1,1);
        for (ll a=2;a<=N;a++){
            ll X=M%a;
            count+=mod[X];
            for(ll b=X;b<=N;b+=a){
                mod[b]++;
            }
        }
        cout<<count<<endl;
    }

return 0;
}