//Problem Link : https://www.spoj.com/problems/AGGRCOW/ 

//Solution : 

#include<bits/stdc++.h>
using namespace std;

bool bs(long long * arr , int c, int n, long long dis){
     int count = 1;
     long long last_position = arr[0];
    
    for(int i = 1; i < n ; i++){
        if(arr[i] - last_position >= dis){
            count++;
            last_position = arr[i];
        }
        
        if(count == c)
            return true;
    }
    
    return false;
        
    
}


int main() {

    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        long long *arr = new long long[n];
        for(int i = 0 ; i < n ; i++)
            cin>>arr[i];
        sort(arr,arr+n);
        long long ans = -1;
        long long start = 0;
        long long end = arr[n-1] - arr[0];
        while(start <= end){
            long long mid = start + (end - start)/2;
            
            if(bs(arr,c,n,mid)){
                ans = mid ;
                start = mid +1;
            }
            else 
                end = mid -1;
            
        }
        cout<<ans<<endl;
        
        
    }
}

