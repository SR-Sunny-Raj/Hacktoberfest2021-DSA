#include<iostream>
using namespace std;
int main()
{
    int i,j,k, temp, arr[10], num, beg, end, mid;
    cout<<"Please enter 10 numbers (with spaces between them): ";
    for(i=0; i<10; i++)
        cin>>arr[i];
        
    for(i=0;i<10;i++)
	  {		
		  for(j=i+1;j<10;j++)
		  {
			  if(arr[i]>arr[j])
			  {
				  temp  =arr[i];
				  arr[i]=arr[j];
				  arr[j]=temp;
			  }
		  }
	  }
	
	for(i=0;i<10;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
	
    cout<<"\nEnter number for searching: ";
    cin>>num;
    beg = 0;
    end = 9;
    mid = (beg+end)/2;
    while(beg <= end)
    {
        if(arr[mid]<num)
            beg = mid+1;
        else if(arr[mid]==num)
        {
            cout<<"\nThe number, "<<num<<" was found at the position "<<mid+1;
            break;
        }
        else
            end = mid-1;
        mid = (beg+end)/2;
    }
    if(beg>end)
        cout<<"\nThe number, "<<num<<" was not found ";
    cout<<endl;
    return 0;
}
