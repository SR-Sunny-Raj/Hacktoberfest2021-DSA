#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    long long t,n,d;
    cin >> t;
    for (long long i = 0 ; i < t; ++i){
        cin >> n >> d;
        long long k[n];
      
        for (long long j = 0; j < n ; ++j){
                cin >> k[j];          
        }

        sort(k,k+n, greater<long long>());
        long long ans = 0;
        for (long long j = 0; j < d+1 ; ++j){
            ans += k[j]; 
        }

        cout << ans << endl;

        
               
    }
}