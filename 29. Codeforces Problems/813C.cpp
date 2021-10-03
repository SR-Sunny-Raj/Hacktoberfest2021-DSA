# Solution to problem: Problem C of codeforces round 813
# Link to problem: https://codeforces.com/contest/813/problem/C

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

lli n, x, a, b, s, ans=ninf;
vi adj[200005];
lli vis[200005], at[200005], bt[200005];

void bfs ()  
{ 
	s=1;
	fill(vis, vis+n+2, 0);

    queue<lli> st; 
    vis[s]=1;
	at[s]=0;
    st.push(s); 

    while (!st.empty()) 
    {   
        s = st.front(); 
        st.pop(); 

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (vis[*i]==0) 
            {   
				at[*i]=at[s]+1;
                st.push(*i); 
                vis[*i]=1;
            }
        }
    }

	s=x;
	fill(vis, vis+n+2, 0);

    vis[s]=1;
	bt[s]=0;
    st.push(s); 

    while (!st.empty()) 
    {   
        s = st.front(); 
        st.pop(); 

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (vis[*i]==0) 
            {   
				bt[*i]=bt[s]+1;
                st.push(*i); 
                vis[*i]=1;
            }
        }
    }
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>x;

	ref(i,1,n-1)
	{
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	bfs();
	
	ref(i,1,n) 
		if (at[i]>bt[i])
			ans=max(ans, 2*at[i]);
	
	cout<<ans<<endl;

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
