#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define eb emplace_back
#define mii map<int, int>
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define mod 1000000007
#define inf 1e18
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define goog(tno) cout << "Case #" << tno <<": "
#define read(x) int x; cin >> x
#define si set<int>
#define sc set<char>
#define iter(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ump   unordered_map
#define mp    make_pair
#define pq_max  priority_queue<ll>
#define pq_min  priority_queue<ll,vi,std::greater<ll> >
#define mid(l,r)   (l+(r-l)/2)
#define bitc(n)    __builtin_popcount(n)
#define ull = unsigned long long;
#define ld = long double
#define vi  vector<int>
#define vb  vector<bool>
#define vvi vector<vi>
#define vll  vector<ll>
#define vvll  vector<vll>
#define pii  pair<int, int>
#define pll  pair<ll, ll>
#define vpii  vector<pii>
#define vpll  vector<pll>
template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
using namespace std;
 
void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
  #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
  #endif
}


int main() {
  clock_t begin = clock();
   file_i_o();
 // Write your code here
   int n; cin >> n;
    map <int, int> mp;

    int k = n;
    while (k--) {
        int temp; cin >> temp;
        mp[temp]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (n <= 0)break;
        cout << n << endl;
        n -= it->second;
    }
  
  #ifndef ONLINE_JUDGE 
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
  #endif 
  return 0;
}