// link to the problem --> https://atcoder.jp/contests/abc151/tasks/abc151_d

// Problem Statement
// Takahashi has a maze, which is a grid of H×W squares with H horizontal rows and W vertical columns.

// The square at the i-th row from the top and the j-th column is a "wall" square if S
// ij
// ​
//   is #, and a "road" square if S
// ij
// ​
//   is ..

// From a road square, you can move to a horizontally or vertically adjacent road square.

// You cannot move out of the maze, move to a wall square, or move diagonally.

// Takahashi will choose a starting square and a goal square, which can be any road squares, and give the maze to Aoki.

// Aoki will then travel from the starting square to the goal square, in the minimum number of moves required.

// In this situation, find the maximum possible number of moves Aoki has to make.

// Sample Input 1
// 3 3
// ...
// ...
// ...

// Sample Output 1
// 4
// If Takahashi chooses the top-left square as the starting square and the bottom-right square as the goal square, Aoki has to make four moves.

// Sample Input 2
// 3 5
// ...#.
// .#.#.
// .#...

// Sample Output 2
// 10

#include <bits/stdc++.h>

using namespace std;

#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define REP(i, a, b) for (ll i = a; i <= b; i++)
#define REP_REV(i, a, b) for (ll i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define endl "\n"

#define pb push_back
#define rsz resize
#define f first
#define s second
#define mp make_pair

using ll = int64_t;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vc = vector<char>;
using ull = unsigned int64_t;
using pi = pair<int, int>;
using vl = vector<int64_t>;
using pl = pair<int64_t, int64_t>;
using vpl = vector<pair<int64_t, int64_t>>;
using msl = map<string, int64_t>;
using vvl = vector<vector<int64_t>>;

const ll MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max();

vector<string> vec_splitter(string s) {
    s += ',';
    vector<string> res;
    while (!s.empty()) {
        res.push_back(s.substr(0, s.find(',')));
        s = s.substr(s.find(',') + 1);
    }
    return res;
}
void debug_out(
    vector<string> __attribute__((unused)) args,
    __attribute__((unused)) int idx,
    __attribute__((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
    if (idx > 0)
        cerr << ", ";
    else
        cerr << "Line(" << LINE_NUM << ") ";
    stringstream ss;
    ss << H;
    cerr << args[idx] << " = " << ss.str();
    debug_out(args, idx + 1, LINE_NUM, T...);
}

#define DBG(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)

template <class T>
void DBGvec(vector<T> a) {
    for (T i : a) cerr << i << " ";
    cerr << endl;
}
template <class T>
void DBGvec_pair(vector<T> a) {
    for (T i : a) cerr << "{" << i.f << " " << i.s << "} ";
    cerr << endl;
}
template <class K, class P>
void DBGmap(map<K, P> a) {
    for (auto i : a) cerr << "{" << i.f << " " << i.s << "} ";
    cerr << endl;
}

bool isPrime(ll n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

unsigned long long factorial(int n) {
    const unsigned int M = MOD;
    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f * i) % M;
    return f;
}

ll expon(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<set<ll>> a(n * m);
    vector<vector<pair<char, ll>>> g(n, vector<pair<char, ll>>(m));
    ll cnt = 0;
    REP(i, 0, n - 1) {
        REP(j, 0, m - 1) {
            cin >> g[i][j].f;
            g[i][j].s = cnt;
            cnt++;
        }
    }
    cnt = 0;
    REP(i, 0, n - 1) {
        REP(j, 0, m - 1) {
            if (g[i][j].f != '#') {
                if (i - 1 >= 0 && g[i - 1][j].f == '.')
                    a[cnt].insert(g[i - 1][j].s), a[g[i - 1][j].s].insert(cnt);

                if (i + 1 < n && g[i + 1][j].f == '.')
                    a[cnt].insert(g[i + 1][j].s), a[g[i + 1][j].s].insert(cnt);

                if (j - 1 >= 0 && g[i][j - 1].f == '.')
                    a[cnt].insert(g[i][j - 1].s), a[g[i][j - 1].s].insert(cnt);

                if (j + 1 < m && g[i][j + 1].f == '.')
                    a[cnt].insert(g[i][j + 1].s), a[g[i][j + 1].s].insert(cnt);
            }
            cnt++;
        }
    }

    ll ans = 0;
    REP(i, 0, n * m - 1) {
        queue<ll> q;
        vb vis(n * m, false);
        vl d(n * m, 0);
        q.push(i);
        vis[i] = true;

        while (!q.empty()) {
            ll u = q.front();
            q.pop();
            for (auto v : a[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    d[v] = d[u] + 1;
                }
            }
        }

        REP(i, 0, sz(d) - 1) {
            ans = max(ans, d[i]);
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}