#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int A[], int low, int high, int x)
{
   if (high >= low)
   {
        int mid = low + (high - low) / 2;

        if (A[mid] == x)
            return mid;
            
        if (mid > low && A[mid - 1] == x)
            return (mid - 1);
            
        if (mid < high && A[mid + 1] == x)
            return (mid + 1);
      
        if (A[mid] > x)
        {
            return BinarySearch(A, low, mid - 2, x);
        }    
 
        return BinarySearch(A, mid + 2, high, x);
}
 
return -1;
}
 
int main()
{
    int arr[] = {5, 1, 4, 23, 30, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int x;
    cout<<"Enter number to be find"<<endl;
    cin>>x;
    
    int result = BinarySearch(arr, 0, n - 1, x);
    if(result == -1)
    {
        cout<<"Element is not present in array";
    }
    else
    {
        cout<<"Element is present at index "<<result;
    }
return 0;
}
