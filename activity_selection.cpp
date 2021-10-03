// Problem Link : https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

//Solution : 

#include<bits/stdc++.h>
using namespace std;

struct act{
  int start;
  int finish;
  
};
 bool compareTo( act a1, act a2){
     return a1.finish < a2.finish ;
 }
int main()
{
    int n;
    cin>>n;
    act arr[n];
    for(int i = 0 ; i < n ; i++){
        int s,f;
        cin>>s>>f;
        arr[i].start = s;
        arr[i].finish = f;
    }
    sort(arr,arr+n,compareTo);
    int count = 1;
    int j = 0;
    for(int i = 1; i < n ; i++){
        if(arr[i].start >= arr[j].finish ){
            count++;
            j = i;
        }
    }
    cout<<count<<endl;
   
    return 0;
}