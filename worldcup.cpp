#include <bits/stdc++.h>
#define M 1000000007
using namespace std ;

int main(){
    int T ;
    cin >> T ;
    while(T--){
        int R, B, L ;
        cin >> R >> B >> L ;
        // Speed up the things for the case when R is odd ..bcz runs can never be odd
        if (R%2==1 || R>6*B || (R>0 && R<4)){
            cout << 0 ;
            continue ;
        }
        if (R==0){
            cout << pow(2, B) ;
            continue ;
        }
        int N = R +1;
        vector<int> vec4(N) ;
        vector<int> vec6(N) ;
        int count_balls = 0 ;
        vec4[0]= vec4[4] = vec6[0] = vec6[4] = 1 ;
        for(int i=5; i<N; ++i){

        }
    }
}


// Didn't complete the question bcz it was a simple adhoc question