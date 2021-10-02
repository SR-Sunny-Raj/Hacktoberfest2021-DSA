/* Problem : 
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.

Input Format :
Integer h

Output Format :
Count % 10^9 + 7

Input Constraints :
1 <= h <= 40

Sample Input 1:
3
Sample Output 1:
15

Sample Input 2:
4
Sample Output 2:
315

*/

//Solution : 

#include <iostream>
using namespace std;
#include <cmath>
#define mod 1000000007

long long balancedBTs(int h) {
  
    long long dp[h + 1]; 
    //base cases 
    dp[0] = dp[1] = 1; 
    for(int i = 2; i <= h; i++) { 
        dp[i] = ((dp[i - 1]%mod) * ((2 * dp [i - 2])%mod + dp[i - 1]%mod)%mod) % mod; 
    } 
    return dp[h]; 
}

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}




