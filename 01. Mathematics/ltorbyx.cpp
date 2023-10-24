#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout<<"Enter a number";
    cin>>n;
    int arr[n];
    int prefix[n];
    memset(prefix,0,sizeof(prefix));
    cout<<"\nEnter n elements\n";
    for(int i=0;i<n;i++)
        cin>>prefix[i];
    arr[0] = prefix[0];
    for(int i=1;i<n;i++)
    {
        arr[i] = prefix[i] - prefix[i-1];
    }
    int l,r,x;
    cout<<"input l,r,x";
    cin>>l>>r>>x;
    arr[l] += x;
    if(r < n-1)
        arr[r+1] -=x;
    prefix[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        prefix[i] = arr[i] + prefix[i-1];
    }
    cout<<"\n\n\n";
    for(int i=0;i<n;i++)
    {
        cout<<prefix[i]<<"  ";
    }






    return 0;
}
