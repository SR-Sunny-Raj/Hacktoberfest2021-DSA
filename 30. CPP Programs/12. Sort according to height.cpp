#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int arr[] = {-1, 150, 190, 170, -1, -1, 160, 180};
    int n  = sizeof(arr)/sizeof(arr[0]);
    vector <int> brr;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != -1)
        { 
            brr.push_back(arr[i]);
            
        }
        
    }
    int m = brr.size();
    sort(brr.begin(), brr.end());
    int crr[n];
    int j = 0;
    for(int i = 0; i < n; i ++)
    {
        if(arr[i] == -1) crr[i] = -1;
        else 
        {
            crr[i] = brr[j];
            j++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << crr[i] << " ";
    }
}
