#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int n;
    cin >> n;
    vector<long long int> arr(n);
    for (long long int i = 0; i < n ; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    long long int mini = arr[0];
    long long int maxi = arr[n - 1];
    long long int diff = maxi - mini;
    long long int minicount = 0;
    long long int maxicount = 0;
    for (long long int i = 0 ; i < n ; i++)
    {
        if (arr[i] == mini)
            minicount++;
        else
            break;
    }
    for (long long int i = n - 1 ; i >= 0 ; i--)
    {
        if (arr[i] == maxi)
            maxicount++;
        else
            break;
    }
    cout << diff << " " << (maxicount * minicount);
    return 0;
}
