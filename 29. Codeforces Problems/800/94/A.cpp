#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t,n,d;
    cin >> t;
    for (int i = 0 ; i < t; ++i){
    cin >> n;
    string s;
    cin >> s;
    // cout << s;
    string ans;
    for(int j = 0 ; j < n; ++j){
        ans += s[n-1];
    }
    cout << ans << endl; 
        
               
    }
}