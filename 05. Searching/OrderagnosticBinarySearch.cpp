/*
Given a sorted array of numbers, find if a given number target is present in the array.
Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order.

    */
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the element you want to find ";
    cin >> t;
    int s = 0;
    int e = n-1;
    bool check = arr[s]<arr[e];
    while(s <= e){
        int mid = s+(e-s)/2;
        if(arr[mid] == target){
            cout<<target<<" Found at index "<<mid;
        }
        if(check){
            if(arr[mid] > target){
                e = mid - 1;
            }
            else{
                s = mid+1;
            }
        }
        else{
            if(arr[mid]>target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
    }
    }
