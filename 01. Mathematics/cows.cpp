#include <bits/stdc++.h>
using namespace std;
long long  n, c;
vector<long long > a;

bool good(long long  x){
    long long cows = 0, last = a[0];
    cows++;
    for(long long i = 1; i < n; i++){
        if(a[i]-last >= x){
            cows++;
            if(cows == c) return true;
            last = a[i];
        }
    }
    return false;
}


long long  binsearch(){
    long long  low = 0, high = 1e16, mid;
    while(low+1 < high){
        mid = (low+high)>>1;
        if(good(mid)){
            low = mid;
        }
        else
            high = mid;
    }
    return low;
}



int main()
{
    cin >> n >> c;
    a.resize(n);
    for(long long  i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    cout << binsearch() << "\n";
    return 0;
}
