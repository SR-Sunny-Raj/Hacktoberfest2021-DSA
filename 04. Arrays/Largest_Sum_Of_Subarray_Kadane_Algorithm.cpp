#include<iostream>
#include<algorithm>

int Largest_Sum_Kadane(int arr[], int n){
    int mx = 0, currSum = 0;
    for(int i = 0; i < n; i++){
        currSum = currSum + arr[i];
        if (currSum < 0) currSum = 0;
        mx = std::max(mx, currSum);
    }
    return mx;
}

int main(){
    int arr[] = {1,5,3,4,-4,3,-6,-8,2,4,3,6,4,4,-3,4};
    int n = sizeof(arr)/sizeof(int);

    std::cout << "The largest subarray sum is " << Largest_Sum_Kadane( arr, n) << std::endl;
    return 0;
}