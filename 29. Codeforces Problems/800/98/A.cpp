#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
    int t,x,y;
    cin >> t;
    for (int i = 0 ; i < t; ++i){
        cin >> x >> y;
        int ab = abs((x-y));
        if (ab == 0 || ab == 1){
            cout << (x+y) << endl;
        }
        else{
            cout << ((x+y)+ab-1) << endl;
        }
        
        
               
    }
}