#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll int t;
	cin>>t;
	while(t--){
	    ll int x, n;
	    cin >> n >> x;
	    ll int s[n], r[n], max;
	    for(ll int i=0; i<n; i++){
	        cin>>s[i]>>r[i];
	    }
	    if(n>=1 && s[0]<=x){
	        max=r[0];
	    }
	    else{
	        max=0;
	    }
	    for(ll int i=1; i<n; i++){
	        if(r[i]>max && s[i]<=x){
	            max=r[i];
	        }   
	    }
	    cout<<max<<endl;
	}
	return 0;
}