// Created by ashryaagr on 7/6/19 (mm/dd/yy) at 11:47 AM .
#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0;i < int(n);i++)
#define All(c) c.begin(), c.end()

#define P2(n) n, n ^ 1, n ^ 1, n
#define P4(n) P2(n), P2(n ^ 1), P2(n ^ 1), P2(n)
#define P6(n) P4(n), P4(n ^ 1), P4(n ^ 1), P4(n)
#define LOOK_UP P6(0), P6(1), P6(1), P6(0)


unsigned int table[256] = { LOOK_UP };

// Function to find the parity
int Parity(int num)
{
    int max = 16;
    while (max >= 8) {
        num = num ^ (num >> max);
        max = max >> 1 ;
    }
    return table[num & 0xff];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T ;
    cin >> T ;
    // I am gonna follow a really bad approach : adhoc/brute-force cauz I could not find any other approach right now
    loop(_, T){
        set<int> s[2] ;
        int Q ;
        cin >> Q ;
        int X ;
        loop(i, Q){
            int R[2] = {0, 0} ;
            cin >> X;
            if (Parity(X)) {
                s[1].insert(X);
                // insert xor of set 1 to 0, 0 to 1
            }else {
                s[2].insert(X);
            }
            cout << R[0] << " " << R[1] << '\n' ;
        }
    }
}
