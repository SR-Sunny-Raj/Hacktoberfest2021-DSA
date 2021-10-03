#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int main()
{


    int d,t, n, ans = 1, count=1;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i];
    }
  
    for(int i = 1 ; i < n ; ++i){
        if(arr[i] > arr[i-1]){
            ++count;
        } 
        else{
            count = 1;
        }
        if(ans < count){
            ans = count;
        }
    }

    cout << ans << endl;
}