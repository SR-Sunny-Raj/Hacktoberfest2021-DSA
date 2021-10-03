// Created by ashryaagr on 7/5/19 (mm/dd/yy) at 9:02 AM .
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

class compare{
public:
    bool operator()(tuple<int, int, int> x, tuple<int, int, int> y) {
        return get<2>(x) > get<2>(y) ;
    } ;
};

priority_queue<tuple<int, int, int>, compare > q ; // tuple(starting, ending, weight)
vector<bool> added ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N ;
    cin >> N ;
    int no_nodes ;
    cin >> no_nodes ;
    added.reserve(N) ;

}
