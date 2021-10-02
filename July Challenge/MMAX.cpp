// Created by ashryaagr on 7/6/19 (mm/dd/yy) at 9:42 AM .
#include <bits/stdc++.h>
#include <cstdint>

using namespace std;
#define loop(i, n) for(int i = 0;i < int(n);i++)

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T ;
    cin >> T ;
    loop(_, T){
        int N , K ;
        intmax_t temp ;
        cin >> N >> temp ;
        K = temp%N ;
        if (2*K==N)
            cout << N-1 << '\n';
        else
            cout << 2*(K>N-K ? N-K : K) << '\n' ;
    }
}
