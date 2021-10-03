// Created by ashryaagr on 7/3/19 (mm/dd/yy) at 5:07 PM .
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int, int> q;
    int N ; cin >>N ;
    vi dist(N) ;
    vector<vii> adj(N) ;
    vector<bool> visited(N) ;
    int no ;
    loop(i, N){
        cin >> no ;
        adj[i] = vii(no) ;
        loop(j, no)
            cin >> adj[i][j].first >>  adj[i][j].second ;
    }
    loop(i, N) dist[i] = INT32_MAX ;
    dist[0] = 0 ;
    q.push({0, 0}) ;
    while(!q.empty()){
        int a = q.top() ; q.pop() ;
        if(visited[a]) continue ;
        visited[a]=1 ;
        for(auto b: adj[a]){
            int u = b.first, w = b.second ;
            if(dist[u]>dist[a]+w){
                dist[u] = dist[a]+w ;
            }
            q.push({-dist[u], u}) ;
        }
    }

}
