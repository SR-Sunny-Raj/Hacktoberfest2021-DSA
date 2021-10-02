//chrononn
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define CASE(t) cout<<"Case #"<<(t)<<": ";
#define endll endl
#define endl '\n'
#define INF 1e18
#define EPS 1e-6
#define deb(x) cout << "[" << (#x) << "=" << x << "]" << '\n'
#define deb2(x,y) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "]" << '\n'
#define deb3(x,y,z) cout << "[" << (#x) << "=" << x << "] [" << (#y) << "=" << y << "] [" << (#z) << "=" << z << "]" << '\n'
#define output(container) for(auto x:container)cout<<x<<" ";cout<<'\n'
#define popcnt __builtin_popcountll
#define precise(x) fixed << setprecision(x)
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pbds tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update >// find_by_order, order_of_key
const ll mod=1000000007;
const ll maxN=50005;

ll ceill(ll a,ll b){return a/b+bool(a%b);}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b, a % b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll power(ll x,ll y){ll res=1;while(y>0){if(y&1)res=(res*x)%mod;x=(x*x)%mod;y>>=1;}return res;}
void bin(unsigned n,string &str){str="";if(n>1)bin(n>>1,str);str+=to_string(n&1);}
bool isPrime(ll n)
{
    if(n<=1)return false;else if(n<=3)return true;else if(n%2==0 || n%3==0)return false;
    for(ll i=5;i*i<=n;i=i+6){if(n%i==0 || n%(i+2)==0)return false;}return true;
}
vector<ll> primeFactors(ll n)
{
    vector<ll>vec;
    while(n%2==0)vec.push_back(2),n/=2;
    for(ll i=3;i<=sqrt(n);i+=2)while(n%i==0)vec.push_back(i),n/=i;
    if(n>2)vec.push_back(n);
    return vec;
}
ll phii(ll n){ll res=n;for(ll i=2;i*i<=n;i++)if(n%i==0){while(n%i==0)n/=i;res-=res/i;}if(n>1)res-=res/n;return res;}
vector<ll>primes,prefp;
void SieveOfEratosthenes()
{
    bool prime[maxN];primes.clear();prefp.clear();prefp.assign(maxN,0);
    memset(prime, true, sizeof(prime));
    for(ll i=2;i*i<maxN;i++)if(prime[i]==true)for(ll j=i*i;j<maxN;j+=i)prime[j]=false;
    for(ll i=2;i<maxN;i++){if(prime[i])primes.push_back(i),prefp[i]=1;prefp[i]+=prefp[i-1];}
}
//vector<ll>fact(maxN);
//void factpre(){fact[0]=1;for(ll i=1;i<maxN;i++)fact[i]=(fact[i-1]*1LL*i)%mod;}
//ll mul(ll a,ll b){return (a*1LL*b)%mod;}
//ll nCr(ll n,ll k){if(k>n)return 0;return mul(fact[n],power(mul(fact[k],fact[n-k]),mod-2));}

/*ll spf[maxN];
void sieve()
{
    spf[1]=1;for(ll i=2;i<maxN;i++)spf[i]=i;for(ll i=4;i<maxN;i+=2)spf[i]=2;
    for(ll i=3;i*i<maxN;i++){if(spf[i]==i)for(ll j=i*i;j<maxN;j+=i)if(spf[j]==j)spf[j]=i;}
}
vector<ll>getfacts(ll x){vector<ll>vec;while(x!=1)vec.push_back(spf[x]),x=x/spf[x];return vec;}*/

/*ll fen[maxN];
void update(ll i,ll val,ll n){i++;for(;i<=n;i+=i&-i)fen[i]+=val;}
ll get(ll i){i++;ll res=0;for(;i>0;i-=i&-i)res+=fen[i];return res;}*/

/*ll phi[maxN];
void Eul_Toi_phi_precompute()
{
    for(ll i=0;i<maxN;i++)phi[i]=i;
    for(ll i=2;i<maxN;i++)if(phi[i]==i){phi[i]=i-1;for(ll j=i+i;j<maxN;j+=i)phi[j]-=phi[j]/i;}
}*/
/*
ll cal(ll r,ll i)
{
	ll zeros=(1LL<<i)-1, n=(1LL<<(i+1));
	r=max(0LL,r-zeros);
	return (r/n)*(n/2)+min(r%n,n/2);
}
ll setcount(ll l,ll r,ll i){return cal(r,i) - cal(l-1,i);}
*/
vector<ll>p,maxi;
ll findd(ll u){return u==p[u]? u:p[u]=findd(p[u]);}
void mergee(ll u,ll v)
{
    u=findd(u),v=findd(v);
    if(maxi[u]==maxi[v])return;
    if(maxi[u]>maxi[v])maxi[v]=maxi[u],p[v]=u;
    else maxi[u]=maxi[v],p[u]=v;
}
void solve()
{
    ll n;cin>>n;
    vector<ll>arr(n);for(ll i=0;i<n;i++)cin>>arr[i];
    p.clear(),p.resize(n+1),maxi.clear(),maxi.resize(n+1);
    for(ll i=1;i<=n;i++)p[i]=i,maxi[i]=arr[i-1];
    ll q;cin>>q;
    while(q--)
    {
        ll t;cin>>t;
        if(t==0)
        {
            ll x,y;cin>>x>>y;
            x=findd(x),y=findd(y);
            if(x==y)cout<<"Invalid query!"<<endl;
            else mergee(x,y);
        }
        else
        {
            ll x;cin>>x;
            cout<<findd(x)<<endl;
        }
    }
}
signed main()
{
    ios;
    ll tc=1; cin>>tc;
    for(ll t=1;t<=tc;t++)
    {
        //CASE(t);
        solve();
    }
    //cout<<endl<<fixed<<setprecision(2)<<1000.0 * clock() / CLOCKS_PER_SEC<< " milliseconds ";
}
