#include <stdio.h>
void swap(int arr[], int i, int j){
    int temp= arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int arr[],int l, int h){
    int pivot=arr[h];
    int i=l-1;
    for(int j=l; j<h;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,h);
    return i+1;
}
void quicksort(int arr[], int l, int h){
    if(l<h){
        int j=partition(arr,l,h);
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,h);
    }
}
int main()
{
    int n;
    printf("Enter number of elements");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");
    for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Sorted array:");
    for(int i=0;i<n;i++){
    printf("%d",arr[i]);
    }
}


