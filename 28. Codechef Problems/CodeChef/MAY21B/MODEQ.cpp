/*
Given integers N and M, find the number of ordered pairs (a,b) such that 1≤a<b≤N and ((M mod a) mod b)=((M mod b) mod a)

.
Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
The only line of each test case contains two integers N, M.

Output:

For each testcase, output in a single line the answer to the problem.
Constraints

    1≤T≤1000

2≤N≤10^6
1≤M≤5⋅10^5
The sum of N over all test cases does not exceed 10^6.
*/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        ll ans = 0;
        vector<ll> mod(n + 1, 1);
        for (ll i = 2; i <= n; i++)
        {
            ll a = m % i;
            ans += mod[a];
            for (ll j = a; j <= n; j += i)
            {
                mod[j]++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}