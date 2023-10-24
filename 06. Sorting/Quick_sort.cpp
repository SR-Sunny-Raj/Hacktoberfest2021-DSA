#include<iostream>
using namespace std;
class quick
{
    public:
    int arr[20],n,i,j,high,low;
    void accept();
    void swap(int *a,int *b);
    int partition(int a[],int low,int high);
    void sort(int a[],int low,int high);
    void display();
};

void quick::accept()
{
    cout<<"\nEnter number of elements : ";
    cin>>n;
    cout<<"\nEnter the unsorted elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    low = 0;
    high = n-1;
}

void quick::swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int quick::partition(int a[],int low,int high)
{
    int pivot = a[high];
    int i = (low-1);
    for(int j = low ; j<=high-1 ; j++ )
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return (i+1);
}

void quick::sort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi = partition(arr,low,high);

        sort(arr,low,pi-1);
        sort(arr,pi+1,high);
    }
}

void quick::display()
{
    cout<<"\n\nThe elements after sorting are : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
}

int main()
{
    quick obj;
    obj.accept();
    obj.sort(obj.arr,obj.low,obj.high);
    obj.display();
    return 0;
}