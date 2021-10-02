#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <tuple>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <climits>
#include <iomanip>
#include <cfloat>

using namespace std;

#define endl "\n"
#define mod 1000000007
#define ff first
#define ss second
#define int long long
#define ld long double
#define ull unsigned long long
#define ld long double
#define pb push_back
#define maxheap priority_queue<int>
#define minheap priority_queue<int,vector<int>,greater<int>>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define gcd(x,y) __gcd(x, y)
#define sp(x,y) fixed<<setprecision(y)<<x
#define loopf(i,x,y) for(int i=x;i<=y;i++)
#define loopb(i,x,y) for(int i=x;i>=y;i--)
#define vi vector<int>
#define mii map<int,int>
#define in(x,n) vi x(n);loopf(i,0,n-1) cin>>x[i];
#define out(x) for(auto i:x) cout<<i<<" ";
#define re(x) int x; cin>>x;

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

#ifndef ONLINE_JUDGE
#define debug(x, s, e) cerr << #x<<" "; _print(x, s, e); cerr << endl;
#else
#define debug(x, s, e);
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(int A[], int s, int e) {cerr << "[ "; for (int i = s; i < e; i++) {_print(A[i]); cerr << " ";} cerr << "]";}


int mul(int a, int b) { return ((a % mod) * (b % mod)) % mod; }
int sub(int a, int b) { return (((a - b) % mod) + mod) % mod; }
int add(int a, int b) { return ((a + b) % mod); }

int power(int x, int y) { if (y == 0) return 1; int p = power(x, y / 2) % mod; p = (p * p) % mod; return (y % 2 == 0) ? p : (x * p) % mod;}
int modInverse(int a) { return power(a, mod - 2);}

map<string, vector<string>> graph;

stack<string> st;

map<string, int> visited;

void TopoSort(string s) {

    visited[s] = 1;

    for (string c : graph[s]) {

        if (visited[c] == 0) {
            TopoSort(c);
        }
    }

    st.push(s);
}

void solve(int t);

int32_t main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

#ifndef ONLINE_JUDGE
    cerr << "Time taken : " << (float)clock() / CLOCKS_PER_SEC << "\n\n";
#endif

    int t = 1;
    // cin >> t;

    for (int testcase = 1; testcase <= t; testcase++) {
        solve(testcase);
        cout << "\n";
    }

    return 0;
}

void solve(int t) {

    graph["a"].pb("d");
    graph["a"].pb("f");
    graph["b"].pb("d");
    graph["b"].pb("e");
    graph["c"].pb("e");
    graph["d"].pb("h");
    graph["e"].pb("g");
    graph["f"].pb("g");

    for (char i = 'a'; i <= 'h'; i++) {

        string o;

        o += i;

        if (visited[o] == 0) {
            TopoSort(o);
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

