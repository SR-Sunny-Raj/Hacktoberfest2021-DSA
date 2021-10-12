/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay
  
  
  Problem statement : A sorted array is input by the user and then a key. 
  Binary search is performed on the array if found then the array index will be output
  else -1 will be the output.
  Example : 
  5 //Array size
  1 2 3 4 5 //Array element 
  3 //Key to be searched
  2 // Element found at 2 index of array
  
*/
#include<bits/stdc++.h>
using namespace std;
int srch(int arr[],int x,int l,int r){
    if(r>=l){
        int mid = l + (r - l) / 2;
        
        if(arr[mid]==x){
            if(mid==l ){
                return mid;
            }
            top:
            if(arr[mid]==arr[mid-1])
            {
                mid--;
                goto top;
            }
            return mid;
        }
        else if(arr[mid]>x){
            return srch(arr,x,l,mid-1);
        }
        else{
            return srch(arr,x,mid+1,r);
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int t;
    cin>>t;
    int search[t];
    for (int i = 0; i < t; i++)
    {
        cin>>search[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout<<srch(arr,search[i],0,n)<<" ";
    }
    return 0;
}
