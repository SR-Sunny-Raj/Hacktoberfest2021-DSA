#include <iostream>
using namespace std;

void Reverse_Array(int array[],int size);

int main()
{
        int i,a[50],size;
    cout<<"Enter array size( Max:50 ) :: ";
    cin>>size;
        cout<<"\nEnter array elements :: \n";

        for(i=0; i<size; i++)
        {
            cout<<"\nEnter arr["<<i<<"] Element :: ";
                cin>>a[i];
        }

  cout<<"\nStored Data in Array :: \n\n";

  for(i=0;i<size;i++)
  {
  cout<<" "<<a[i]<<" ";
  }
        // Calling Reverse Array Values Function
        Reverse_Array(a,size);
        cout << "\n\nReversed Array Values are :: " << endl;
    for(i=0;i<size;i++)
    {
      cout<<" "<<a[i]<<" ";
    }

    cout<<"\n";

        return 0;
}

//------Reverse Array Function---------------

void Reverse_Array(int array[],int size)
{
        int temp;
        size--;
        for (int i=0;size>=i;size--,i++)
    {
                temp=array[i];
                array[i]=array[size];
                array[size]=temp;
        }
}
