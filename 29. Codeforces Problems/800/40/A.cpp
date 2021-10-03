#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, d;
    // cin >> t;
    // for (int i = 0 ; i < t; ++i){
    cin >> n;
    string s;
    cin >> s;
    // int ans = 0;
    int temp = 0;
    // int len = s.length();
    int flag = 0;
    for (int j = 0; j < n-1; ++j)
    {
        if (s[j] != s[j+1])
        {
            ++temp;
            ++j;
        }
        
    }

   
    cout << n-temp << endl;
}