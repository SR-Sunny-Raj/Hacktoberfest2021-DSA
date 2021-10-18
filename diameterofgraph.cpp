#include <iostream>
using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PT 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define pb push_back
#define ppb pop_back

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifdef SOLUTION
#define debug(x) cerr << #x <<" "; _print(x); cerr <<endl;
#else
#define debug(x)
#endif


void graph(){
    ll n,m,k;
    cin>>n>>m>>k;
    if(m>n*(n-1)/2 || m<n-1) {
        cout<<"NO"<<endl;
    }
    else if(n==1&&k<=1){
        cout<<"NO"<<endl;
    }
    else if(n==2&&k<=2){
        cout<<"NO"<<endl;
    }
    else if(n>=3&&(m<n-1 || m<n*(n-1)/2 && k<=3 || m>=n*(n-1)/2 && k<=2)){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}

int main() 
{
#ifdef SOLUTION
    freopen("Error.txt","w",stderr);
#endif
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int t;
cin>>t;
while(t--){

graph();
}
return 0;
}
