#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t,x,y;
    cin >> t;
    for (int i = 0 ; i < t; ++i){
        cin >> x >> y;
        // int ab = abs((x-y));
        if ( (2*x) <= y){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        
        
               
    }
}