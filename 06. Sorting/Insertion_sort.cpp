#include<iostream>
using namespace std;
class insertion
{
    private:
        int arr[20],n,i,j;
    public:
    void accept();
    void sort();
    void display();
};

void insertion::accept()
{
    cout<<"\nEnter number of elements : ";
    cin>>n;
    cout<<"\nEnter the unsorted elements : "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}

void insertion::sort()
{
    int temp;
    for(i=1;i<n;i++)
    {
        temp = arr[i];
        j = i - 1;
        while((temp<arr[j]) && (j>=0))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void insertion::display()
{
    cout<<"\n\nThe elements after sorting are : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<"   ";
    }
}

int main()
{
    insertion obj;
    obj.accept();
    obj.sort();
    obj.display();
    return 0;
}