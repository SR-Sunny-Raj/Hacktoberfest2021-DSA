#include<iostream>
using namespace std;


int max(int a,int b)
{
	if(a>b)
	return a;
	else 
	return b;
}
 
void sort(int arr[], int startIndex, int endIndex)
{
	int key;
	for (int j = 1; j < endIndex; j++)
	{
		key = arr[j];
		int i = j - 1;
		while (i >= startIndex - 1 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
}

int binary_search(int f[],int s,int n)
{
	for(int i=0;i<n;i++)
	{
		if(f[i]<= s &&s<=  f[i + 1])
		{
			return i;
		}
	}
}


void  DYNAMIC_ACTIVITY_SELECTOR(int s[],int f[], int n)
{
	sort(s,0,n);
	sort(f,0,n);
	int m[n];
	int p[n];
	int k,i;
	for ( i = 0; i < n; i++)
	{
		k=binary_search(f, s[i],n);
		m[i]=max(m[i-1], 1+ m [k]);
	}
	i = k;
    while  ( i > 0)
    {
		if (m[i] == m[i-1])
         {
		  p[i] = 0;
          i = i - 1;
         }
        else
        {
         i = binary_search(f, s[i],n);
         p[i] = 1;
        }
    }
	for(int i=1;i<n;i++)
	{
		if(p[i]==1)
		{
			cout<<"( "<<s[i]<<", "<<f[i]<<" "<<endl;
		}
			}		
}


int main()
{
	int s[6] = {1, 3, 0, 5, 8, 5};
	int f[6]={2, 4, 6, 7, 9, 9};
	int n = 6;
	DYNAMIC_ACTIVITY_SELECTOR(s,f, n);
	
	return 0;
}
