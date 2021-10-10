#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
            int x;
            cin>>x;
            arr.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        arr[arr[i]] = arr[arr[i]] +n ;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]/n > 1)
        {
            cout<<" "<<i<<" , "<< arr[i]/n<<" ";
        }
    }



    return 0;
}
