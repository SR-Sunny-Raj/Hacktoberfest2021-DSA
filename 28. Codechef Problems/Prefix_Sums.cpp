#include <iostream>
#include <algorithm>
#include <vector>
//#include <math.h>
//#include <iomanip>
//#include <string.h>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//#include <numeric>
//#include <unordered_map>
//#include <unordered_set>
#define ll long long int
//#define ull unsigned long long int
//#define mod 1000000007
//#define loop(n) for(int i = 1;i<=n;i++) cout<<seats[i]<<" ";
//#define loopIN(n) for(int i = 0;i<n;i++) cin>>arr[i];
//#define nextln cout<<"\n";
using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<int> first;
    vector<int> second(n/2);
    ll sum = (n*(n+1))/2;
    ll f = 0,s = (n/2)-1;
    if(sum%2 != 0) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        ll start = 1,end = n;
        bool flag = true;
        while(start<=end){
            if(flag == true){
                flag = false;
                first.push_back(start);
                first.push_back(end);
                }
                else{
                    flag  = true;
                    second[f]=start;
                    f++;
                    second[s] = end;
                    s--;
                    }
                    start++;
                    end--;
            }
            for(auto it : first) cout<<it<<" ";
            cout<<endl;
            for(auto it : second) cout<<it<<" ";
            cout<<endl;
        }
    return;
    }    
int main(){
ios::sync_with_stdio(false);
cin.tie(0);    
ll t = 1;
cin>>t;
for(int i = 1;i<=t;i++){
solve();
}

return 0;
}
