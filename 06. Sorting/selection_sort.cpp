// Selection sort takes minimum from the unsorted part
// and takes it to the sorted part of the array
// for theory refer https://www.geeksforgeeks.org/selection-sort/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[100];

	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(int i=0;i<n-1;i++)
	{
		int min_index=i;

		for(int j=i+1;j<n;j++)
		{
			if(a[min_index]>a[j])
			{
				min_index=j;
			}
		}

		swap(a[min_index],a[i]);

	}


	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
