#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int main()
{


    int flag = 0,t, n, ans = 0;
    // // cin >> t;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; ++i){
        cin >> arr[i];
    }
  
    for(int i = 1 ; i < n-1 ; ++i){
        if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
            ans+=1;
       
        }
        if(arr[i-1] > arr[i] &&  arr[i] < arr[i+1] ){
            ans+=1;
           
        }
    }

    cout << ans << endl;
}