//For a given string s determine whether there is a sequence of actions leading to an empty string.


#include <bits/stdc++.h>
using namespace std;
 
//upper_bound(begin(),end(),key)
//lower_bound(begin(),.end(),key)
//fractional = modf(n, &whole);
// next_permutation(arr[i].begin(),arr[i].end())
//transform(s.begin(),s.end(),s.begin(),::tolower)
//*max_element(ans.begin(),ans.end())
// stringstream geek(s); ll x=0; geek>>x; cout<<x;
// stringstream ss;  ss<<a;  string s;  ss>>s;  cout<<s;
// gcd(a+k,b+k)=gcd(b−a,a+k)
// set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s3,s3.begin()));
// int k=int(find(v.begin(),v.end(),a)-v.begin()); (int y=v[k]; )((k+1 to v.end() will remain as it is...)
// copy_backward(v.begin(),v.begin()+k,v.begin()+k+1); (...0 to k-1 will shift to right by 1 and kth element will com at pos 0 (v[0]=y)
/* to calculate all prime factors:-
   1) While n is divisible by 2, print 2 and divide n by 2.
   2) After step 1, n must be odd. Now start a loop from i = 3 to square root of n.
      While i divides n, print i and divide n by i. After i fails to divide n, increment i by 2 and continue.
   3) If n is a prime number and is greater than 2, then n will not become 1 by above two steps. So print n if it is greater than 2.
*/
#define ll               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define M                 1000000007
 
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
 
const long long INF=1e18;
const int32_t MM=998244353;
 
void solve()
{
   string s;
   cin>>s;
   map<int,int> mp;
   for(int i=0;i<s.size();i++)
   {
      mp[s[i]-65]++;
   }
   if(mp[0]+mp[2]==mp[1]||(mp[1]==mp[0]&& mp[2]==0)||(mp[2]==mp[1]&& mp[0]==0))
      cout<<"YES"<<"\n";
   else
      cout<<"NO"<<"\n";
}
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   //freopen("input1.txt", "r", stdin);
   //freopen("output1.txt", "w", stdout);
 
int t;
cin>>t;
while(t--)
   {
solve();
}
   return 0;
}
 