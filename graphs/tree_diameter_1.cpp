// Created by ashryaagr on 7/4/19 (mm/dd/yy) at 12:08 PM .
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
queue<int> q ;
vector<bool> visited ;
vi dist ;
vi dist1 ;

void bfs(int x){
    visited[x] = true ;
    q.push(x) ;
    dist[x] = 0 ;
    while(!q.empty()){
        int s = q.front() ;
        q.pop();
        for(auto i : adj[s]){
            if (visited[i]) continue ;
            visited[i] = true ;
            dist[i] = dist[s]+1 ;
            q.push(i) ;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin) ;
    int N ; // No of nodes
    cin >> N ;
    adj.reserve(N) ;
    visited.reserve(N) ;
    dist.reserve(N) ;
    dist1.reserve(N) ;
    int no ;
    loop(i, N){
        cin >> no ;
        adj[i] = vi(no) ;
        loop(j, no)
            cin >> adj[i][j] ;
    }
    int x = 0 ;
    bfs(x) ;
    loop(i, N) {
        swap(dist[i], dist1[i]) ;
        visited[i] = false ;
    }
    cout << *max_element(dist1.begin(), dist1.end()) << "\n";
    loop(i, N) cout << dist1[i] << "d1\t" ;
    x = distance(max_element(dist1.begin(), dist1.end()), dist1.begin() );
    cout << x << '\n' ;
    bfs(x);
    cout << *max_element(dist.begin(), dist.end()) << "\n";
}
// Theres some bug in it
