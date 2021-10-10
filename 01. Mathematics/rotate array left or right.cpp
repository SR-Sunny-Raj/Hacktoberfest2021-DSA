#include<bits/stdc++.h>
#include<vector>
using namespace std;
void leftrotate(vector<int> &arr,int n)
{
    int temp = arr[0];
    int i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[i] = temp;

}


void rotarr(vector<int> &a, int nor )
{

	int n = a.size();
	for(int i=1;i<= nor ; i++)
        leftrotate(a,n);

}
int main()
{
    int n;
    cout<<"enter n";
    cin>> n;
    vector<int> a(n);
    cout<<"enter elements";
    for(int i=0;i<n;i++)
        cin>> a[i];
    int nor;
    cout<<"enter nor";
    cin>>nor;
    rotarr(a,nor);
    for(int i=0;i<n;i++)
        cout<<" "<< a[i]<<" ";


    return 0;
}
