//Question
// You have n chains, the i-th chain consists of ci vertices. Vertices in each chain are numbered independently from 1 to ci along the chain. In other words, the i-th chain is the undirected graph with ci vertices and (ci−1) edges connecting the j-th and the (j+1)-th vertices for each 1≤j<ci.

// Now you decided to unite chains in one graph in the following way:

// the first chain is skipped;
// the 1-st vertex of the i-th chain is connected by an edge with the ai-th vertex of the (i−1)-th chain;
// the last (ci-th) vertex of the i-th chain is connected by an edge with the bi-th vertex of the (i−1)-th chain.

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> ii;
typedef vector<long long int> vi;
typedef vector<vector<long long int>> vvi;
typedef vector<pair<long long int, long long int>> vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) (c).begin(), (c).end()
#define sz(a) ((long long int)(a).size())
#define lli long long int
#define ull unsigned long long int
#define ld long double
#define ref(i, x, y) for (long long int i = (x); i <= (y); ++i)
#define reb(i, x, y) for (long long int i = (x); i >= (y); --i)
#define trf(c, it) for (auto it = (c).begin(); it != (c).end(); it++)
#define trb(c, it) for (auto it = (c).end() - 1; it != (c).begin() - 1; it--)
#define debs(x) cout << #x << " = " << x << " "
#define debn(x) cout << #x << " = " << x << "\n"
#define tc(t)        \
    long long int t; \
    cin >> t;        \
    while (t--)
#define endl '\n'

const long long int mod = 1e9 + 7;
const long long int pinf = 9223372036854775807;
const long long int ninf = -9223372036854775807;
vector<lli> adj_list[1010];

lli n;
lli countz = 0;

vi mp[300100];
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli n, x, st, sm, cnt, pw, flg, k, m, y, a, b, l, s1, s2, z, q, p;
    tc(t)
    {
        cin >> n;
        lli arr_a[n], arr_b[n], arr_c[n];
        for (x = 0; x < n; x++)
            cin >> arr_c[x];
        for (x = 0; x < n; x++)
            cin >> arr_a[x];
        for (x = 0; x < n; x++)
            cin >> arr_b[x];
        lli curr_val = abs(arr_a[1] - arr_b[1]);
        lli fin_ans = 0;
        for (x = 1; x < n; x++)
        {
            curr_val += 2;
            fin_ans = max(fin_ans, curr_val + arr_c[x] - 1);
            if (x != n - 1)
            {
                a = arr_a[x + 1];
                b = arr_b[x + 1];
                if (a > b)
                    swap(a, b);
                curr_val = max(curr_val + a - 1 + arr_c[x] - b, b - a);
                if (a == b)
                    curr_val = 0;
            }
        }
        cout << fin_ans << endl;
    }
}