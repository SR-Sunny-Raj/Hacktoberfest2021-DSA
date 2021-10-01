// Find Ceil of an element in a Sorted Array
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 8, 10, 10, 12, 19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int element = 5;
    int start = 0;
    int end = n-1;
    vector<int> res;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(element==arr[mid]){
            cout << arr[mid];
            break;
        }
        else if(element<arr[mid]){
            res.push_back(arr[mid]);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    cout << *min_element(res.begin(), res.end());
    return 0;
}
