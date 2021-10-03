// Question:
//Overall there are m actors in Berland. Each actor has a personal identifier — an integer from 1 to m (distinct actors have distinct identifiers). Vasya likes to watch Berland movies with Berland actors, and he has k favorite actors. He watched the movie trailers for the next month and wrote the following information for every movie: the movie title, the number of actors who starred in it, and the identifiers of these actors. Besides, he managed to copy the movie titles and how many actors starred there, but he didn't manage to write down the identifiers of some actors. Vasya looks at his records and wonders which movies may be his favourite, and which ones may not be. Once Vasya learns the exact cast of all movies, his favorite movies will be determined as follows: a movie becomes favorite movie, if no other movie from Vasya's list has more favorite actors.

// Help the boy to determine the following for each movie:

// whether it surely will be his favourite movie;
// whether it surely won't be his favourite movie;
// can either be favourite or not.

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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    lli n, x, st, sm, cnt, pw, flg, k, m, y, l, s1, s2, z, q, p;
    // tc(t)
    {
        cin >> m >> k;
        lli a[k];
        for (x = 0; x < k; x++)
            cin >> a[x];
        set<lli> actor_set;
        for (x = 0; x < k; x++)
            actor_set.insert(a[x]);
        cin >> n;
        string names[n];
        lli num_actors[n];
        vector<lli> starrers[n];
        for (x = 0; x < n; x++)
        {
            cin >> names[x];
            cin >> num_actors[x];
            for (y = 0; y < num_actors[x]; y++)
            {
                cin >> q;
                starrers[x].push_back(q);
            }
        }
        vector<pair<lli, lli>> ans;
        lli count = 0, ambig = 0;
        for (x = 0; x < n; x++)
        {
            lli wrong_actor = 0;
            count = 0, ambig = 0;
            for (y = 0; y < num_actors[x]; y++)
            {
                if (starrers[x][y] == 0)
                    ambig++;
                else if (actor_set.find(starrers[x][y]) != actor_set.end())
                    count++;
                else
                    wrong_actor++;
            }
            if (k - count > m - count - wrong_actor - ambig)
            {
                lli tem = k - count - m + count + wrong_actor + ambig;
                count += tem;
                ambig -= tem;
            }
            z = min(k - count, ambig);
            ans.push_back({count, count + z});
        }
        lli max_val = 0, flag = 0, min_sure = 0, min_ki_freq = 0, second_highest_max_val;
        for (x = 0; x < n; x++)
        {
            min_sure = max(min_sure, ans[x].first);
            if (ans[x].first == ans[x].second)
            {
                if (ans[x].first >= max_val)
                    second_highest_max_val = max_val, max_val = ans[x].first, flag = 0;
            }
            else
            {
                if (ans[x].second > max_val)
                    second_highest_max_val = max_val, max_val = ans[x].second, flag = 1;
            }
        }
        for (x = 0; x < n; x++)
            if (ans[x].first != ans[x].second && ans[x].first == min_sure && ans[x].second == max_val)
                min_ki_freq++;
        lli zer_flag = 1;
        for (x = 0; x < n; x++)
            if (ans[x].second > min_sure && ans[x].first != min_sure)
                zer_flag = 0;
        for (x = 0; x < n; x++)
        {
            if (ans[x].second < min_sure)
                cout << 1 << endl;
            else if (ans[x].first >= max_val)
                cout << 0 << endl;
            else if (ans[x].second < max_val)
                cout << 2 << endl;
            else if (ans[x].first == min_sure && min_ki_freq == 1 && zer_flag)
                cout << 0 << endl;
            else
                cout << 2 << endl;
        }
    }
}
