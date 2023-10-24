#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    long long t,n,d;
    cin >> t;
    for (int i = 0 ; i < t; ++i){
    string s;
        cin >> s;
        int len = s.length();
        int balopen =0;
        int balclose = 0;
        int count = 0;

        
        for(int j = 0; j < len ; ++j){
            if(s[j] == '(' ){
                ++balopen;
            }
            if(s[j] == ')' && balopen > 0){
                --balopen;
                ++count;
            }
            if(s[j] == '[' ){
                ++balclose;
            }
            if(s[j] == ']' && balclose > 0){
                --balclose;
                ++count;
            }


        } 
        cout << count << endl;
        
               
    }
}