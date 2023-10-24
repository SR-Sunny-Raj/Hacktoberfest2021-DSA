#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n, m,d;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        cin >> m;
        
        if (n%m == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}