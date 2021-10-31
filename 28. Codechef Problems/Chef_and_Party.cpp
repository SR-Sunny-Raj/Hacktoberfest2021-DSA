/*
CODECHEF PROBLEM:-
PROBLEM CODE: CHFPARTY
LINK: https://www.codechef.com/problems/CHFPARTY */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int n,i,j,t,count;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> arr;
        for(i=0;i<n;i++)
        {
            cin>>j;
            arr.push_back(j);
        }
        count = 0;
        sort(arr.begin(),arr.end());
        for(i=0;i<n;i++)
        {
            if(arr[i] <= count)
            {
                count++;
            }
        }
        cout<<count<<"\n";
    }
	// your code goes here
	return 0;
}


