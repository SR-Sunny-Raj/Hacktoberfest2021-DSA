# Solution to problem: Problem D of codeforces round 818
# Link to problem: https://codeforces.com/contest/818/problem/D

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
#define trf(c, it) for (auto it = (c).begin(); it != (c).end(); ++it)
#define trb(c, it) for (auto it = (c).end() - 1; it != (c).begin() - 1; --it)
#define debs(x) cout << #x << " = " << x << ' '
#define debn(x) cout << #x << " = " << x << '\n'
#define tc(t) int t; cin >> t; while (t--)
#define endl '\n'

const long long int mod = 1e9 + 7;
const long long int pinf = 9223372036854775807;
const long long int ninf = -9223372036854775807;

lli n, a, c[100005], a1, b1, mx;
set<ii> s;
map<lli, lli> sz;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>n>>a;
    
    ref(i,0,n-1)
    {
        cin>>c[i];
        mx=max(mx, c[i]);
    }

    ref(i,1,min(1000000LL, mx+5))
        if (i!=a)
            s.insert({0, i});

    ref(i,0,n-1)
    {
        if(c[i]==a)
        {
            sz[a]+=1;
            while (s.size()>0 && (*(s.begin())).ff<sz[a])
            {
                a1 = (*(s.begin())).ff;
                b1 = (*(s.begin())).ss;
                s.erase({a1, b1});
            }
        }

        else
        {
            if (s.find({sz[c[i]], c[i]}) != s.end())
            {
                s.erase({sz[c[i]], c[i]});
                sz[c[i]]=sz[c[i]]+1;
                s.insert({sz[c[i]], c[i]});
            }
        }
    }

    if ((lli)s.size()==0) cout<<-1<<endl;
    else cout<<(*(s.begin())).ss<<endl;

	return 0;
}


// WA
// 1. overflow
// 2. re-initialize global variables for every test case
// 3. edge cases like n=1 or some type of cases missing
 
// Run time error
// 1. division by zero
// 2. array bounds
 
// TLE
// 1. move declarations outside
