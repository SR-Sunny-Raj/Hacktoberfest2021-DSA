// Created by ashryaagr on 7/6/19 (mm/dd/yy) at 6:30 PM .
#include <bits/stdc++.h>

using namespace std;
#define loop(i, n) for(int i = 0;i < int(n);i++)
#define All(c) c.begin(), c.end()

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T ;
    cin >> T;
    loop(_, T){
        int N ;
        cin >> N ;
        list<int> L ;
        int temp ;
        int penalty=0 ;
        loop(i, N){
            cin >> temp ;
            L.push_back(temp);
        }
        loop(i, N-1){
            auto ptr=L.end() ;
            ptr-- ;
            int sum=*L.begin()+*ptr;
            auto end_ptr = ptr ;
            auto next_ptr = L.begin() ;
            next_ptr++;
            for(auto itr=L.begin() ; itr!= end_ptr ; itr++, next_ptr++){
                if (*itr+*next_ptr < sum) {
                    sum= *itr + *next_ptr ;
                    ptr = itr ;
                }
            }
            *ptr = sum ;
            penalty += sum ;
            if (ptr==end_ptr)
                ptr-- ;
            else
                ptr++ ;
            L.erase(ptr) ;
        }
        cout << penalty << '\n' ;
    }

}
