#include <iostream>
using namespace std;

// Menu-driven program in C++ to Create, display, insert,search and delete elements of an array

void disp(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void insert(int arr[],int &n, int pos, int ele)
{
    for(int i=n;i>=pos;i--)
    arr[i+1]=arr[i];
    arr[pos]=ele;
    n+=1;
}
void del(int arr[],int &n, int pos, int ele)
{
    for(int i=pos;i<n;i++)
    arr[i]=arr[i+1];
    n-=1;
    cout<<ele<<"deleted";
}
int search(int arr[],int n, int ele)
{
    int ind=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            ind=i;
        }
    }
    return ind;
}

int main() {
	// your code goes here
	int n,ch,pos,ele,d,s,end;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	do{
	cout<<"Menu\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Search\n6.Exit\n";
	cin>>ch;
	switch(ch)
	{
	    case 2:
	    disp(arr,n);
	    break;
	    case 3: 
	    cout<<"Enter position & element";
	    cin>>pos>>ele;
	    insert(arr,n,pos,ele);
	    break;
	    case 4:
	    cout<<"Enter element to be deleted";
	    cin>>d;
	    pos=search(arr,n,d);
	    if(pos==-1)
	    cout<<"Element not found";
	    else
	    del(arr,n,pos,d);
	    break;
	    case 5:"Enter element to search";
	    cin>>s;
	    pos=search(arr,n,s);
	    cout<<"Element found at"<<pos+1;
	    break;
	    case 6:break;
	}
	cout<<"Continue: 1/0?";
	cin>>end;
	}while(end==1);
	return 0;
}