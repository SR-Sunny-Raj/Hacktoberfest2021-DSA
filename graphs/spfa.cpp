// Created by ashryaagr on 7/3/19 (mm/dd/yy) at 4:56 PM .
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
    int N ;
    cin >> N ;
    queue<int> qu ;
    vector<tuple<int, int, int>> vec(N) ;
    int a, b, w ;
    loop(i, N){
        cin >>a >>b >> w;
        vec.push_back(make_tuple(a, b, w)) ; // Important......Difficult to figure out the way to implement this
    }
    vi dist(N) ;
    loop(i, N){
        dist[i] = INT32_MAX ;
    }
    qu.push(0) ;
    dist[0] = 0 ;
    // We will find minimum distance from node 0
    loop(i, N-1){
        for(auto q : vec){
            tie(a, b, w) = q ;
            if (dist[b]>dist[a]+w)
                qu.push(b) ;
            dist[b] = min(dist[b], dist[a] + w) ;
        }
    }
    loop(i, N) cout << dist[i] << "\t";
}
 // leaving uncompleted ....use a queue to select the edge to update