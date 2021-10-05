// Link to problem: https://codeforces.com/problemset/problem/50/A

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, b, n, m;
    cin>>a>>b;
    n = ( int(min(a,b)/2) * (max(a,b)) );
    m = (a*b) - (2*n);
    m = m/2;
    cout<<n + m<<endl;
}
