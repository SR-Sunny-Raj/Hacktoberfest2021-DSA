//Problem Link : https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/

//Solution :

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll> pl;
typedef vector<int>	vi;
typedef vector<ll> vl;
typedef vector<pii>	vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int solve(int * a, int n) {
    int i, j;
   int lis[n];
   int lds[n];
   lis[0] = 1;
   lds[n-1] = 1;
   Fo(i,1,n){
       lis[i] = 1;
       Fo(j,i-1,-1){
           if(a[j]<a[i])
                lis[i] = max(lis[i],lis[j]+1);
       }
   }
   Fo(i,n-2,-1){
       lds[i] = 1;
       Fo(j,n-1,i){
           if(a[j]<a[i])
                lds[i] = max(lds[i],lds[j]+1);
       }
   }

   int maxi = INT_MIN;
   fo(i,n) maxi = max(maxi,lis[i]+lds[i]-1);
   return maxi;


} 	
	

int longestBitonicSubarray(int *input, int n) {
		
	
     	return solve(input,n);
     	
     	
 	}

int main() {
  int n, input[100000];
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  cout<<longestBitonicSubarray(input, n);
  return 0;
}


