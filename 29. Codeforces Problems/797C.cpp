# Solution to problem: Problem C of codeforces round 797
# Link to problem: https://codeforces.com/contest/797/problem/C

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

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	lli n; 
	string str; stack <char> t;
	char mn[100005], ggez;

	cin>>str;
	n=str.length();

	mn[n-1]=str[n-1];          
	ggez=str[n-1];

	reb(i,n-2,0)
	{
		mn[i]=ggez;
		ggez=min(ggez, str[i]);
	}

	ref(i,0,n-1)
	{
		t.push(str[i]);
		while(t.size()>0 && i+1<n && t.top()<=mn[i+1] && t.top()<=str[i+1])
		{
			cout<<t.top();
			t.pop();
		}
	}

	while(t.size())
	{
		cout<<t.top();
		t.pop();
	}

	cout<<endl;

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
