// Order Not Known Search - When we don't know whether it's ascending or descending
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int asc_search(int arr[], int n){
    int element = 2;
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(element==arr[mid]){
            return mid;
            break;
        }
        else if(element<arr[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int desc_search(int arr[], int n){
    int element = 2;
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(element==arr[mid]){
            return mid;
            break;
        }
        else if(element<arr[mid])
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int main() {
    int arr[7] = {20, 15, 12, 11, 9, 3, 2};
    int n = 7;
    int element = 2;
    if(n==1){
        if (element==arr[0]) 
            cout << 0;
    }
    else {
        if(arr[0]<arr[1])
            cout << asc_search(arr, n);
        else
            cout << desc_search(arr, n);
    }
    return 0;
}
