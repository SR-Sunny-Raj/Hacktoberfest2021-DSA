#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)              //taking input
	cin>>arr[i];                   
	
	int sum=INT_MIN;
	int prevSum=0;
	for(int i=0;i<n;i++){
	    prevSum+=arr[i];           //keeping track of previous sum
	    if(prevSum>sum)
	    sum=prevSum;
	    if(prevSum<=0)            
	    prevSum=0;
	}
	cout<<sum;
	
	return 0;
}
