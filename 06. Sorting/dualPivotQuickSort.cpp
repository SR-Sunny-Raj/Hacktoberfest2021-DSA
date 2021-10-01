//Nandita Manchikanti
//Below is the implementation for Dual Pivio Quick Sort

#include<iostream>
using namespace std;

void printarr(int array[],int n)
{
    cout<<"The sorted array is :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<array[i]<<endl;
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int make_part(int arr[], int low, int high, int* left)
{
    if (arr[low] > arr[high])
    {
        swap(&arr[low], &arr[high]);
    }
    int less = low + 1;
    int great = high - 1;
    int k = low + 1;

    int left_pivot = arr[low];
    int right_pivot = arr[high];

    while (k <= great)
    {
        if (arr[k] < left_pivot)
        {
            swap(&arr[k], &arr[less]);
            less++;
        }
        else if (arr[k] >= right_pivot)
         {
            while (arr[great] > right_pivot && k < great)
            {
                great--;
            }
            swap(&arr[k], &arr[great]);
            great--;

            if (arr[k] < left_pivot)
            {
                swap(&arr[k], &arr[less]);
                less++;
            }
        }
        k++;
    }
    less--;
    great++;

    swap(&arr[low], &arr[less]);
    swap(&arr[high],&arr[great]);

    *left = less;
    return great;
    
}

void dual_pivot_quicksort(int arr[], int low, int high)
{
    if (low < high) {
        int left, right;
        right = make_part(arr, low, high, &left);

        dual_pivot_quicksort(arr, low, left - 1);
        dual_pivot_quicksort(arr, left + 1, right - 1);
        dual_pivot_quicksort(arr, right + 1, high);
    }
}
int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[100];
    cout<<"Enter the elements of array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    dual_pivot_quicksort(arr,0,n-1);
    printarr(arr,n);
    return 0;
}