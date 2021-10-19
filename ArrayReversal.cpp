#include <iostream>

using namespace std;

int reverse(int arr[], int start, int end) {
    
    int temp;
    
    if(start < end) {
        temp        = arr[start];
        arr[start]  = arr[end];
        arr[end]    = temp;
        
        // recursive function call
        reverse(arr, start+1, end-1);
    }
    
    return 0;
}

int main() {
    
    int n, arr[100], i;
    
    cout << "Enter the size of an array \n";
    cin  >> n;
    
    cout << "Enter an element of an array \n";
    
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    reverse(arr, 0, n-1);
    
    cout << "Reverse of an array is \n";
    
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
