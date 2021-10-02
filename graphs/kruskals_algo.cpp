// Created by ashryaagr on 7/4/19 (mm/dd/yy) at 8:21 PM .
#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0;i < int(n);i++)

typedef vector<int>::iterator vitr;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

class compare{
public:
    bool operator()(tuple<int, int, int> x, tuple<int, int, int> y) {
        return get<2>(x) > get<2>(y) ;
    } ;
};

vector<tuple<int, int, int>> vec ;
vi link ;
vi size ;
priority_queue<tuple<int, int, int>, compare > q ;

int find(int x){
    while(link[x]!=x){
        x = link[x] ;
    }
    return x ;
}

void unite(int x, int y){ //  x and y are the nodes
    int a = find(x) ;
    int b = find(y) ;
    if (b>a) swap(a, b) ;
    size[a] += size[b];
    link[b] = link[a] ;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int no_nodes ;
    cin >> no_nodes ;
    int N ;
    cin >> N ;
    vec.reserve(no_nodes) ;
    link.reserve(no_nodes) ;
    size.reserve(no_nodes) ;
    int a, b, w ;
    loop(i, N){
        cin >> a >> b >> w ;
        q.push({a, b, w}) ;
    }
    loop(i, no_nodes) {
        link[i] = i ;
        size[i] = 1 ;
    }
    int i=0 ;
    while(i<no_nodes){
        tie(a, b, w) = q.top() ;
        if (!same(a, b)){
            unite(a, b) ;
            vec.emplace_back(tuple<int, int, int>(a, b, w));
            i++ ;
        }
    }
    loop(j, no_nodes)
        cout << get<0>(vec[i]) << get<1>(vec[i]) << get<2>(vec[i]) << '\n' ;
}
