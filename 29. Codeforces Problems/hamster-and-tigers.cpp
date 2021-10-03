//Question
// Today there is going to be an unusual performance at the circus — hamsters and tigers will perform together! All of them stand in circle along the arena edge and now the trainer faces a difficult task: he wants to swap the animals' positions so that all the hamsters stood together and all the tigers also stood together. The trainer swaps the animals in pairs not to create a mess. He orders two animals to step out of the circle and swap places. As hamsters feel highly uncomfortable when tigers are nearby as well as tigers get nervous when there's so much potential prey around (consisting not only of hamsters but also of yummier spectators), the trainer wants to spend as little time as possible moving the animals, i.e. he wants to achieve it with the minimal number of swaps. Your task is to help him.

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
    // tc(t)
    {
        cin >> n;
        string s;
        cin >> s;
        lli h_count = 0, t_count = 0;
        for (x = 0; x < n; x++)
            if (s[x] == 'H')
                h_count++;
            else if (s[x] == 'T')
                t_count++;
        lli ans = 1e7;
        for (x = 0; x < n; x++)
        {
            lli curr_ans = 0;
            for (y = x; y < x + h_count; y++)
            {
                if (s[y % n] != 'H')
                    curr_ans++;
            }
            ans = min(ans, curr_ans);
        }
        cout << ans << endl;
    }
}
