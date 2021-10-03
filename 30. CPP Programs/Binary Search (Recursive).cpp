#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fo(i,a,b) for(int i=a ; i<b ; i++)
#define foe(i,a,b) for(int i=a ; i<=b ; i++)
#define endl '\n'
#define ff first
#define ss second
#define MOD 1000000007

int binarySearch(int arr[], int n, int s, int e, int key)
{
    if(s>e) return -1;
    int mid = (s+e)/2;
    if(key == arr[mid]) return mid;
    if(key<mid) return binarySearch(arr, n, s, mid-1, key);
    if(key>mid) return binarySearch(arr, n, mid+1, e, key);
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++) cin>>arr[i];
    int key; cin>>key;
    cout<<binarySearch(arr, n, 0, n-1, key)<<endl;
    
    return 0;
}