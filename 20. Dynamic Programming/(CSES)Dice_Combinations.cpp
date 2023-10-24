#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n;
	cin>>n;
	vector<ll> combinations(n+1,0);
	combinations[0]=1;
	for(int index=1;index<=n;index++){
	for(int diceValue=1;diceValue<=6;diceValue++){
	if(diceValue>index)
	break;
	combinations[index]=(combinations[index]+combinations[index-diceValue])%1000000007;
	}
	}
	cout<<combinations[n];
}
