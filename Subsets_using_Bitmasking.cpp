/* By Aditya Raj */
// ------------- //

/* 
   Program to generate subsets using Bitmasking.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;     // taking length of the array as input
    int a[n];

    // taking the elements of the array

    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }

    // Generating all non-empty subsets using Bitmasking

    for(int i = 0;i < (1<<n);i++)   // all 2^n combinations
    {
        for(int j = 0;j < n;j++)
        {
            if(i & (1<<j))
            {
                cout<<a[j]<<" ";    // Printing the subsets
            }
        }
        cout<<endl;
    }
    return 0;
}