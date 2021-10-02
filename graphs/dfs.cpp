// Created by ashryaagr on 7/3/19 (mm/dd/yy) at 2:02 PM .
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
vector<bool> visited ;
int Sum ; // Stores the sum of all nodes
void dfs(int i){
    if (visited[i]) return;
    visited[i] = 1 ;
    Sum += i ;
    for(int j: adj[i]){
        dfs(j) ;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N ; // No of nodes
    cin >> N ;
    adj.reserve(N) ;
    visited.reserve(N) ;
    int no ;
    loop(i, N){
        cin >> no ;
        adj[i] = vi(no) ;
        loop(j, no)
            cin >> adj[i][j] ;
    }
    dfs(0) ;
    cout << Sum ;
}
