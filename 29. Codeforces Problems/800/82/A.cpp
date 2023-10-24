#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t,n,d;
    cin >> t;
    for (int i = 0 ; i < t; ++i){
    // cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int temp = 0;
    int len = s.length();
    int flag = 0;
    for(int j = 0 ; j < len; ++j){
        if(s[j] == '1'){
            flag = 1;
            ans += temp;
            temp = 0;
        }
        if(flag == 1 && s[j] == '0'){
            ++temp;
            
        }
        
    }
    
    cout << ans << endl;
   
        
               
    }
}