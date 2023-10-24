/*
You are given an array a[0…n−1]=[a0,a1,…,an−1] of zeroes and ones only. Note that in this problem, unlike the others, the array indexes are numbered from zero, not from one.

In one step, the array a is replaced by another array of length n according to the following rules:

First, a new array a→d is defined as a cyclic shift of the array a to the right by d cells. The elements of this array can be defined as a→di=a(i+n−d)modn, where (i+n−d)modn is the remainder of integer division of i+n−d by n.
It means that the whole array a→d can be represented as a sequence
a→d=[an−d,an−d+1,…,an−1,a0,a1,…,an−d−1]
Then each element of the array ai is replaced by ai&a→di, where & is a logical "AND" operator.
For example, if a=[0,0,1,1] and d=1, then a→d=[1,0,0,1] and the value of a after the first step will be [0&1,0&0,1&0,1&1], that is [0,0,0,1].

The process ends when the array stops changing. For a given array a, determine whether it will consist of only zeros at the end of the process. If yes, also find the number of steps the process will take before it finishes.

Sample Input:
5
2 1
0 1
3 2
0 1 0
5 2
1 1 0 1 0
4 2
0 1 0 1
1 1
0

Sample OutPut:
1
1
3
-1
0

*/


#include <ext/pb_ds/assoc_container.hpp> // Common file 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less 
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long 
#define pb push_back
#define PI 3.141592653
#define pll pair<ll,ll>
#define V vector
#define F first
#define S second
#define INF LLONG_MAX
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll lcm(ll a, ll b){    return (a / __gcd(a, b)) * b;}

void dfs(V<ll> &v, V<ll> &used, ll u, ll d){
    //cerr << u << endl;
    ll n = v.size();
    used[u] = 1;
    if(v[u] == 1 && !used[(u+n-d)%n])  dfs(v, used, (u+n-d)%n, d);
    if(v[u] == 0)   used[u] = 1;
    else    used[u] = used[(u+n-d)%n]+1;
}
void solve(){
    ll n, d;
    cin >> n >> d;
    V<ll> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    V<ll> used(n);
    for(int i = 0; i < n; i++){
        if(used[i] || v[i] == 0) continue;
        ll j = i;
        while(1){
            //cerr << j << endl;
            if(used[j] && j == i){
                cout << -1 << endl;
                return;
            }
            else if(used[j])    break;
            if(v[j] == 1)  used[j] = 1, j = (j+n-d)%n;
            else{
                used[j] = 1;
                break;
            }
        }
    }
    used.assign(n, 0);
    for(int i = 0; i < n; i++){
        if(used[i] || v[i] == 0) continue;
        dfs(v, used, i, d);
    }
    ll res = 1;
    for(int i = 0; i < n; i++)
        res = max(res, used[i]);
    cout << res-1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int i = 1; i <= T; i++){
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}