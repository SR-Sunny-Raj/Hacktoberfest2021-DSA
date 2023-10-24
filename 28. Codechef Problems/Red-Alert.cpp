#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n, d, h, u=0;
	    string ans = "NO";
	    cin>>n>>d>>h;
	    int A[n];
	    for(int i=0; i<n; i++){
	        cin >> A[i];
	    }
	    for(int j=0; j<n; j++){
	        if(A[j]>0){
	            u+=A[j];
	        }
	        else{
	            if(u<d){
	                u=0;
	            }
	            else{
	                u-=d;
	            }
	        }
	        if(u>h){
	            ans = "YES";
	            break;
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}