/***************************
 A. Next Round
time limit per test:  3 seconds
memory limit per test:  256 megabytes

"Contestant who earns a score equal to or greater than the k-th place finisher's score will advance to the next round, as long as the contestant earns a positive score..." — an excerpt from contest rules.

A total of n participants took part in the contest (n ≥ k), and you already know their scores. Calculate how many participants will advance to the next round.

Input
The first line of the input contains two integers n and k (1 ≤ k ≤ n ≤ 50) separated by a single space.

The second line contains n space-separated integers a1, a2, ..., an (0 ≤ ai ≤ 100), where ai is the score earned by the participant who got the i-th place. The given sequence is non-increasing (that is, for all i from 1 to n - 1 the following condition is fulfilled: ai ≥ ai + 1).

Output
Output the number of participants who advance to the next round.


Sample input
8 5
10 9 8 7 7 7 5 5
Sample output
6



 *******************/

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define nline '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define set_bits __builtin_popcountll
#define sz(v) ((int)((v).size()))
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) ((v).begin()), ((v).end())
#define allr(w) ((w).rbegin()), ((w).rend())

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

/*********************************/

bool isPowOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

bool cmp1(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

ll min3(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}

ll min4(ll a, ll b, ll c, ll d)
{
    return min(a, min(b, min(b, c)));
}

ll max3(ll a, ll b, ll c)
{
    return max(a, max(b, c));
}

ll max4(ll a, ll b, ll c, ll d)
{
    return max(a, max(b, max(b, c)));
}

/*********************************/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vi v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    int temp = v[k - 1];
    if (temp == 0)
    {
        int ans = 0;
        rep(i, 0, n)
        {
            if (v[i] > temp)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    else
    {
        int ans = 0;
        rep(i, 0, n)
        {
            if (v[i] >= temp)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
