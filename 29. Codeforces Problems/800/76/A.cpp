#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main(){
    int t,n,a, b,x,d;
    cin >> t;
    for (int i = 0 ; i < t; ++i){
    cin >> n;    
    cin >> x;
    cin >> a;
    cin >> b;
    if((abs(a-b)+x) >= n){
        cout << n-1 << endl;
    } 
    else{
        cout << (abs(a-b)+x) << endl;
    }
    
   
        
               
    }
}