#include<bits/stdc++.h>
using namespace std;

bool check(int cows, long long positions[], int n, long long distance)
{
    int count=1;
    long long last_position = positions[0];
    for(int i=1; i<n; i++)
    {
        if(positions[i]-last_position>=distance)
        {
            last_position = positions[i];
            count++;
        }
        
        if(count==cows)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,c;
        cin >> n >> c;
        long long positions[n];
        for(int i=0; i<n; i++)
        {
            cin >> positions[i];
        }
        sort(positions, positions+n);
        long long start=0;
        long long end = positions[n-1]-positions[0];
        
        long long ans=-1;
            
            while(start<=end)
            {
                long long mid = start + (end-start)/2;
                
                if(check(c, positions, n, mid))
                {
                    ans = mid;
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
        cout << ans << endl;
    }
    
    return 0;
}
