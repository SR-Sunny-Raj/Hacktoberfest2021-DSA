#include <bits/stdc++.h>
using namespace std;

int main() {


           long int a;
           cin>>a;
           for(int b=0;b<a;b++){
               
              long int n,x;
              cin>>n>>x;
              
              long int arr[n+1];
              for(int i=0;i<n;i++) cin>>arr[i];
              arr[n]=99999999999;
              sort(arr,arr+(n+1));
              
              long long int same=1;
              long long int op=0;
              
              long long int hold=arr[0];
              long long int count=1;
              for(int i=1;i<=n;i++){
                  if(arr[i]!=hold){
                      if(count>=same){
                          same=count;
                          op=0;
                      }
                       long long int z=x^hold;
                  long long int u = lower_bound(arr, arr+n+1, z) - arr;
                  
                  if(arr[u]==z){
                      long long int v = upper_bound(arr, arr+n+1, z) - arr;
                      long long int t=v-u;
                      long long int k=t;
                      if(z!=hold) k+=count;
                      if(k>same){
                          same=k;
                          op=t;
                      }
                      else if(k==same){
                          if(t<op) op=t;
                      }
                      
                  }
                     count=1;
                     hold=arr[i];
                  }
                 else{
                     count++;
                 }
                  
                  
                  
              }
              
               
              cout<<same<<" "<<op<<endl; 
                  
               
               
           }
          
}
