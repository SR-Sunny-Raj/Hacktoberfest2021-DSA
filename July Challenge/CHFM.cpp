// Created by ashryaagr on 7/5/19 (mm/dd/yy) at 5:43 PM .
#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0;i < int(n);i++)
#define All(c) c.begin(), c.end()

typedef vector<int>::iterator vitr;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T ;
    int N ;
    double a ;
    loop(_, T){
        cin >> N ;
        vi A(N) ;
        loop(i, N)
            cin >> A[i] ;
        a = accumulate(All(A), 0.0)/N ;
        if (ceil(a)!=floor(a) || (find(All(A), a)==A.end()))
            cout << "Impossible" << '\n' ;
        else
            cout << distance(A.begin(), find(All(A), a)) + 1 << '\n' ;
    }
}
