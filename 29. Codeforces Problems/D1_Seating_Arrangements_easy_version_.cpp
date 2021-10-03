// author: Karthik Hegde
// solution to codeforces problem http://codeforces.com/contest/1566/problem/D1
// author's submission at codeforces: http://codeforces.com/contest/1566/submission/128636827 



#include<bits/stdc++.h>
using namespace std;
 
 
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;
 
#define ook order_of_key
#define fbo find_by_order
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<long long> vll;
#define PI acos(-1.0)
#define EPS 1e-9
#define INF 1000000000
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define pb push_back
#define mkp make_pair
#define sqr(a) ((a) * (a))
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define FOR(i, l, r) for(int i=int(l); i<=int(r); i++)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
void print_out(int x){
    cout<<"Case #"<<x<<": ";
}
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t;cin>>t;
    while(t--){
        int n, m;cin>>n>>m;
 
        vpii A(m);
        FOR(i, 0, m-1){
            int x;cin>>x;
            A[i] = {x, i};
        }
 
        sort(A.begin(), A.end(), [&](pii a, pii b){
            if(a.first==b.first)return a.second > b.second;
            return a.first<b.first;
        });
 
 
        int ans = 0;
        set<pii> st; // ind, pos;
        for(int i=0; i<m; i++){
            int ind = A[i].second;
            int pos = i;
            auto it = st.lower_bound({ind, pos});
            
            for(auto x=st.begin(); x!=it; x++){
                if((x->second)<pos)ans++;
            }
 
            st.insert({ind, pos});
        }
 
        cout<<ans<<"\n";
 
    }   
 
    return 0;
}