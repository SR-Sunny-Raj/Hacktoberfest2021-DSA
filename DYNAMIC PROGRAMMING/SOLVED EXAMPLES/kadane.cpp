//An efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers that has the largest sum

// Explanation:
// 1. Look for all positive contiguous segments of the array
// 2. Save maximum sum contiguous segment among all positive segments in a variable(max_so_far)
// 3. Compare the positive sum with max_so_far and update max_so_far if it is greater.

//Input: 
//8   -> size of array
//-2 -3 5 -1 -2 1 5 -9   -> array numbers

//Output: 8

#include<bits/stdc++.h>
using namespace std;

int Kadane(int arr[],int size){
    int max_cur=arr[0],max_so_far=arr[0];
  
    for(int i=1;i<size;i++){
        max_cur=max(max_cur+arr[i],arr[i]);
        max_so_far=max(max_cur,max_so_far);
    }
    return max_so_far;
}

int main(){
    int size;
    cin >> size;
    int arr[size];
      for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    cout<<Kadane(arr,size)<<"\n";
}
