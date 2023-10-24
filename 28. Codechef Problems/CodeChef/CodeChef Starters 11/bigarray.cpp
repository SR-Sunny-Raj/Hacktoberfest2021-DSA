#include <bits/stdc++.h>
using namespace std;

#define ff(a, c)        for (int(a) = 0; (a) < (c); (a)++)
#define w(x)            int x; cin >> x; while(x--)
#define int             unsigned long long

int32_t main() {
    
   w(t) {
      int n, s;
      cin >> n >> s;

      int ans = n * (n + 1) / 2;
      
      ans = ans - s;
      
      if (ans >= 1 and  ans <= n)  cout << ans << endl;
      else cout << -1 << endl;
   }

   cout.clear();
   cin.clear();
   return 0;
}