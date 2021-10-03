// Created by ashryaagr on 7/3/19 (mm/dd/yy) at 9:50 PM .
#include <bits/stdc++.h>

using namespace std;
#define M 1000000007
#define loop(i, n) for(int i = 0;i < int(n);i++)
#define All(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define each(i, c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

typedef vector<int>::iterator vitr;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> adj ;
vi toleaf ;
vi max_length ;

void dfs(int s, int e) {
    int maxi=0 ;
    for (auto u : adj[s]) {
        if (u != e){
            dfs(u, s);
        }
        maxi = max(maxi, toleaf[u]) ;
    }
    toleaf[s] = maxi +1 ;
    if (adj[s].size()==1) toleaf[s] = 0 ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N ;
    cin >> N ;
    adj.reserve(N) ;
    toleaf.reserve(N) ;
    max_length.reserve(N) ;
    int no ;
    loop(i, N){
        cin >> no ;
        adj[i] = vi(no) ;
        loop(j, no)
            cin >> adj[i][j] ;
    }
    dfs(0, 0) ;
    cout << *max_element(toleaf.begin(), toleaf.end()) << '\n' ;
}
