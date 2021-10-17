// CREATED BY    DEVIL'S_NE5T   AKA    HARSH GUPTA

// NOT A PRO CODER XD
// JUST SOMEONE WHO IS INTERESED IN THE WORLD OF CODING
// JUST SO I MENTION THAT ALTHOUGH I LIKE CODING BUT DEBUGGING MAKES ME FEEL SICK


#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll              long long
#define ull             unsigned long long
//COMMON DATA STRUCTURES
//----------------------
#define vll             vector<ll>
#define vpairll         vector<pair<ll,ll>>
#define mpll            map<ll,ll>
#define mpcl            map<char,ll>
#define setll           set<ll>
//COMMON OPERATIONS 
//-----------------
#define setbits         __builtin_popcountll //count number of 1 in binary
#define leadzero        __builtin_clz //count leading zeroes in binary
#define tailzero        __builtin_ctz //coutn tail zero
#define pb              push_back
#define pfrt            push_front
#define lb              lower_bound
#define ub              upper_bound
#define F               first
#define S               second
#define endl            "\n"
#define all(v)          v.begin(),v.end()
#define revall(v)       v.end(),v.begin()
#define MEM(a, b)       memset(a, (b), sizeof(a))    
#define loop(i,a,b)     for(ll i=a;i<b;i++)
#define rev(i,a,b)      for(ll i=b-1;i>=a;i--)
#define foreach(it,l)   for(auto it=l.begin();it!=l.end();it++)
#define reveach(it,l)   auto it = l.end();it--;for(it;it!=l.begin();it--)

// ________________________________________________________________________________________________________________
//PBDS
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
    ordered_set;
//find_by_order() return the iterator to the element at xth(0-based) position
//order_of_key() returns number of elements in set which are strictly less than x

#define PI           3.1415926535897932384626433832795
const ll M      =    1e9+7;
const ll i1     =    300005;


// ________________________________________________________________________________________________________________

//CODE HERE........

void harsh_op(ll test_case){

    ll n; cin>>n;
    ll ans = 0;

    ordered_set s; 
    ll ex ; cin>>ex;
    s.insert(ex);

    for(ll i=1;i<n;i++){
        ll x; cin>>x;
        ll pos = s.order_of_key(x);
        ll pos1 = s.order_of_key(x+1);
        ans += min(pos,i-pos1);
        s.insert(x);
    }

    cout<<ans<<endl;

}


int main(){
    fast;
    // seive();
    // factorial();
    

    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
    
    ll ttcc = 1;
    cin>>ttcc;
    ll test_case=0;
    while(ttcc--){
        harsh_op(test_case);
        test_case++;
    }

}
