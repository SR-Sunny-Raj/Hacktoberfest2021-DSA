#include<bits/stdc++.h>

#define int uint64_t
#define tses int testcases; cin >> testcases; while(testcases--)
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// pcode : ADDNDIV
// question_link: https://www.codechef.com/START13A/problems/ADDNDIV

using namespace std;

int32_t main(void){
  fio;
  
  tses{
    int a, b;
    cin >> a >> b;
    
    int flag = 1;

    while(a != 1){
      int temp = __gcd(a, b);
      if(temp == 1){
        flag = 0;
        break;
      }

      a /= temp;
    }

    if(flag == 1){
      cout << "YES" << endl;
    }else cout << "NO" << endl;
  }

  return 0;
}
