#include <bits/stdc++.h>
using namespace std;
#define ffor(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int solve(ll n ,vector<ll> &arr )
{
	vector<vector<pii>> v;
	v.resize(200109);
	
	rep(i,n){
		int x = arr[i];
		v[x].pb(mp(i,i+1));
		v[x].pb(mp(i+n,i+n+1));
	}
	int ans = 0;

	repA(i,1,200100){
		if(sz(v[i])) ans = i;
		sort(all(v[i]));
		int jj = 0;
		repA(j,1,sz(v[i])-1){
			while(v[i][j].fst>v[i][jj].snd) jj++;
			if(v[i][j].fst==v[i][jj].snd&&v[i][j].snd-v[i][jj].fst<=n){
				v[i+1].pb(mp(v[i][jj].fst,v[i][j].snd));
			}
		}
	}
	return ans;
}
int solve1(ll n , vector<ll> arr)
{
    set<int> s;
	ffor(i,0,n)
	{
		s.insert(i);
	}
	bool temp = true;
	int cnt = 0;
	while(temp)
	{
		temp = false;
		
		int prev , crnt ;
        cnt = 0;
        for(auto it : s)
        {
            if(cnt == 0)
            {
                prev = it;
                cnt++;
                continue;
            }
            else if(cnt == 1)
            {
                crnt = it;
                if(arr[prev] == arr[crnt])
                {
                    arr[crnt]+= 1;
                    arr[prev] = 0;
                    s.erase(s.find(prev));
                    temp = true;
                }
                prev  = crnt;
            }
        }
        
        //ps(fstidx , lstidx);
        if(s.size() >= 2)
        {
        	int fstidx = *s.begin();
        	int lstidx = *(--s.end());
        	if(fstidx != lstidx)
        	{
        		if(arr[fstidx] == arr[lstidx])
        		{
        			arr[fstidx]+= 1;
                    arr[lstidx] = 0;
                    s.erase(s.find(lstidx));
                    temp = true;
        		}
        	}
        }
	}
	return (*max_element(all(arr)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
    int t = 1000000;
    vector<ll> arr;
    ll n;
	while(t--)
    {
         
        n =(rand()%(9)) + 1;
        arr.clear();
        arr.resize(n);
        ffor(i,0,n)
        {
            arr[i] = (rand() %6) + 1;
        }
        ll ans2 = solve(n , arr);
        ll ans1 = solve1( n , arr);
        if(ans1 == ans2)
        {
            cout<<"1";
        }
        else
        {
            cout<<endl;
            cout<<n<<endl;
            for(int i=0; i < n ;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<ans1<<endl;
            cout<<ans2<<endl;
            cout<<endl;
            break;
        }
       
        
    }

    return 0;
}


