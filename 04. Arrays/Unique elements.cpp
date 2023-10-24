#include <iostream>
using namespace std;
int non_repeating_elements(int arr[], int n)
{
int i,j;
int count = 1;
for(i = 0; i < n; i++)
{
for(j = 0; j < n; j++)
{
if(arr[i] == arr[j] && i != j)
break;
}
if(j == n )
{
cout << "\nNon-repeating element [" << count << "]" << " : " << arr[i] << endl;
++count;
}
}
return -1;
}
int main()
{
int n,i;
cout << "\nEnter the number of elements : ";
cin >> n;
int arr[n];
cout << "\nInput the array elements : ";
for(i = 0; i < n; i++)
{
cin >> arr[i];
}
non_repeating_elements(arr, n);
return 0;
}

