#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
	    int n;
	    cin>>n;
	    int arr[n],brr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>brr[i];
	    }
	    int crr[n];
	    crr[0]=arr[0];
	    for(int i=1;i<n;i++){
	        crr[i]=arr[i]-arr[i-1];
	    }
	    int count=0;
	    for(int i=0;i<n;i++){
	        if(brr[i]<=crr[i]){
	            count++;
	            //cout<<brr[i]<<" "<<arr[i]<<" "<<count<<endl;
	        }
	    }
	    cout<<count<<endl;
	    
	}
	return 0;
}

