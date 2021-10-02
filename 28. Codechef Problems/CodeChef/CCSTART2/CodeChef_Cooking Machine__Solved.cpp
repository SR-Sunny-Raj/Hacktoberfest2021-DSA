/* -------------------------------------------------------------------------- */
/*                       Cooking Machine  Problem Code: COOKMACH                       */
/* -------------------------------------------------------------------------- */

/** In a unit of time, CHEFZA can pick one setting (let's say its current value is v) and change it in one of the following ways.
    If v is even, change this setting to v/2. If v is odd, change it to (v − 1)/2.
    Change setting to 2 × v
    The receipt is given as a list of integer values the settings should be set to. 
    It is guaranteed that each destination setting can be represented as an integer power of 2.
 * find the minimum number of operations needed to set up a particular setting of the machine.
*/

/*
    Input:
        The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
        The only line of each test case contains two integers A and B denoting the initial and desired values of the setting, respectively.

    Output:
        For each test case, output a single line containing minimum number of operations Chefza has to perform in order to set up the machine.

    Constraints
        1 ≤ T ≤ 200
        1 ≤ A ≤ 107
        1 ≤ B ≤ 107, and B is an integer power of 2

    Sample Input 1:
        6
        1 1
        2 4
        3 8
        4 16
        4 1
        1 4

    Sample Output 1:
        0
        1
        4
        2
        2
        2

    Explanation
        In the first test case, you don't need to do anything.
        In the second test case, you need to multiply 2 by 2 and get 4. This is done in 1 operation.
        In the third test case, you need to obtain 1 from 3 and then multiply it by 2 three times to obtain 8. A total of 4 operations.
        In the fourth test case, multiply 4 by 2 twice.
        In the fifth test case, divide 4 by 2 twice.
        In the sixth test case, multiply 1 by 2 twice.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isPower(ll x)
{
    return x && (!(x&(x-1)));
}


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll ans=0;
        while(a!=b){
            if(a>b){
                if(a%2==0){
                    a=a/2;
                    ans++;
                }
                else{
                    a=(a-1)/2;
                    ans++;
                }
            }
            else{
                if(b%a==0){
                    ll num=b/a;
                    if(isPower(num)){
                        a=a*2;
                        ans++;
                    }
                }
                else{
                    if(a%2==0){
                        a=a/2;
                        ans++;
                    }
                    else{
                        a=(a-1)/2;
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
