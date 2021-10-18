/******************************
         codificador10
*******************************/
#include <bits/stdc++.h>
using namespace std;
// clang-format off
#define 			ll long long int
#define 			nline '\n' 
#define 			vii vector<int>
#define 			ss second
#define 			pb push_back
#define 			ppb pop_back
#define 			sz(x) ((int)(x).size())
#define 			all(x) (x).begin(), (x).end()
#define 			rep(i, a, b) for (int i = a; i < b; i++)
#define 			rrep(i, a, b) for (int i = b - 1; i >= a; i--)
#define 			precision cout.precision(numeric_limits<double>::max_digits10);
#define 			fastio() ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
// clang-format on
/*------------------------------------------------SOLVE----------------------------------------------*/
//This variation of ibnary search can be usefull in cases where we have to find the max or min possible values that
//obey a certain cobdition
int invar(int num, vector<long long> &v)
{
    int l = -1, r = v.size();
    //this range is just to ensure there are atleast positive and neg both values
    int md;
    //T T T T F F F -> boolen array
    // v[l] <=num// invariant
    // v[r]>num
    while ((r - (l + 1)))
    {
        md = l + (r - l) / 2;
        if (v[md] <= num)
            l = md;
        else
            r = md;
    }

    if (v[l] == num)
        return r; // index is l(0 based) so l+1 can be written as r
    else
        return 0;
}

void KuchKuchHotaHai()
{
    int n;
    cin >> n;
    vector<long long> v;
    for (int i = 1; i <= n; i++)
        v.push_back(i * i);
    sort(v.begin(), v.end());
    int num;
    cin >> num;
    cout << invar(num, v);
}

/*-----------------------------------------------testcase--------------------------------------------*/

signed main()
{
    fastio();
    int t = 1;
    //cin>>t;
    for (int i = 1; i <= t; i++)
    {
        KuchKuchHotaHai();
    }
    return 0;
}