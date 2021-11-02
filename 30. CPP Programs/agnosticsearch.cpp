#include <iostream>
using namespace std;

int binary_search(int arr[], int start, int end, int key) 
{ 
    int ascending = 0;

    if (arr[start] < arr[end])
        ascending = 1;


    while (start <= end) 
    { 
        int mid = start + (end - start) / 2; 

        // Check if key is present at mid 
        if (arr[mid] == key) 
            return mid; 

        if(ascending == 1)
        {
            // If key greater, ignore left half 
            if (arr[mid] < key) 
                start = mid + 1; 

            // If key is smaller, ignore right half 
            else
                end = mid - 1; 

        } else {
            // If key greater, ignore right half 
            if (arr[mid] < key) 
                end = mid - 1; 

            // If key is smaller, ignore left half 
            else
                start = mid + 1; 
        }
    } 

    // if we reach here, then element was 
    // not present 
    return -1; 
} 

int main(void) 
{ 
   int n;
   cin >> n;
    int  z;
   int  arr[n];
   for(int i=0;i<n;i++)
   {
       cin  >>   arr[i];
   }
   int key;
   cin >> key;
    z=binary_search(arr,0,n,key);
    if(z==-1)
    {
        cout  << "index is not present "  <<  endl;
    }
    else
    {
        cout << "the element is present at index " << z << endl;
        cout << "the elemet is present at position "  << z+1 <<  endl;
    }
    return 0; 
} 
