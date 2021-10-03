// C++ code to implement Fibonacci series
#include <bits/stdc++.h>
using namespace std;
 
// Function for fibonacci
int vis[10000000]{0};
int fib(int n)
{
    if(!n)return 0;
    if (vis[n])return vis[n];
    if(vis[n-2]==false)vis[n-2]=fib(n-2);
    if(vis[n-1]==false)vis[n-1]=fib(n-1);
    return vis[n-1] + vis[n-2];
}
 
// Driver Code
int main()
{   vis[1]=vis[2]=1; 
    // Initialize variable n.
    int n = 5;
    cout<<"Fibonacci series of 5 numbers is: ";
 
    // for loop to print the fiboancci series.
    for (int i = 0; i < n; i++)
    {
        cout<<fib(i)<<" ";
    }
    return 0;
}
