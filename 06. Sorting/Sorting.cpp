#include <iostream>
#include <algorithm>
 using namespace std;
 int main() {
 int n,t;
 cin >> t;        
 while(t--){
     cin>>n;
     int gl[n],b[n];
     for(int i = 0;i<n;i++){
         cin>>gl[i];}
     for(int i=0;i<n;i++){
         cin>>b[i];
     }
     sort(gl,gl+n);
     sort(b,b+n);
     int j=n-1,c=0;
     for(int i=0;i<n;i++){
         if(gl[i]% b[j] ==0 || b[j]% gl[i] == 0){
             c++;}
        j = j-1; }
     cout<<c<<endl;}
  return 0;  }