#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int main()
{


    long long  t, n, a, b, c ;
    cin >> n;
    cin >> t;
  
    a = (n/2)/(t+1);
    b = t*a;
    c = n - a - b;
    

    

    cout << a << " " << b << " " << c << " " << endl;
}