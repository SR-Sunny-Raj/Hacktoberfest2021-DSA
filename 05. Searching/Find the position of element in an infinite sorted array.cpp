#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int A[], int low, int high, int x)
{
    if (high>=low)
    {
        int mid = low + (high - low)/2;
        if (A[mid] == x)
            return mid;
        if (A[mid] > x)
            return BinarySearch(A, low, mid-1, x);
        return BinarySearch(A, mid+1, high, x);
    }
    return -1;
}

int position(int A[], int key)
{
   int low = 0;
   int high = 1;
   while(key > A[high])
   {
     low = high;
     high = high * 2;
   }
   return BinarySearch(A, low, high ,key);
}

int main()
{
    int A[] = {4,6,8,9,13,16,18,24,45,78,99,105,130,157};
      
    int result,x;
    cout<<"Enter number to be find"<<endl;
    cin>>x;
    
    result = position(A, x);
    if (result==-1)
        cout << "Element not found";
    else
        cout << "Index of element found at " << result;
    return 0;
}

