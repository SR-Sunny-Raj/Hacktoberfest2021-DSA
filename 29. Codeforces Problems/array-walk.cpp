//Question
// You are given an array a1,a2,…,an, consisting of n positive integers.

// Initially you are standing at index 1 and have a score equal to a1. You can perform two kinds of moves:

// move right — go from your current index x to x+1 and add ax+1 to your score. This move can only be performed if x<n.
// move left — go from your current index x to x−1 and add ax−1 to your score. This move can only be performed if x>1. Also, you can't perform two or more moves to the left in a row.
// You want to perform exactly k moves. Also, there should be no more than z moves to the left among them.

// What is the maximum score you can achieve?
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
        cin >> n >> k >> z;
        lli arr[n];
        for (x = 0; x < n; x++)
            cin >> arr[x];
        lli sum = 0;
        lli ans = 0;
        for (x = 0; x <= k; x++)
            sum += arr[x];
        vector<lli> ve;
        multiset<lli> ms;
        for (x = 0; x <= k; x++)
            ms.insert(arr[x]);
        ans = sum;
        lli max_lim = z;
        for (x = 1; x <= max_lim; x++)
        {
            lli max_sum = 0;
            for (y = 0; y <= k - 2 * x; y++)
            {
                max_sum = max(max_sum, arr[y] + arr[y + 1]);
            }
            lli curr_sum = sum;
            for (y = k; y > k - 2 * x; y--)
                curr_sum -= arr[y];
            curr_sum += max_sum * x;
            ans = max(ans, curr_sum);
        }
        cout << ans << endl;
    }
}