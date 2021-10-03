#include <bits/stdc++.h>

using namespace std ;

class compare {
    int val ;
public:
    compare(int num) : val(num) {}

    int operator()(int x) const {
        return (val | x) == val ;
    }
};

int main(){
    int tCases ;
    cin >> tCases  ;
    int N ;
    for (int i=0; i<tCases; ++i){
        cin >> N ;
        int ans = 0 ;
        vector<int> vec(N) ;
        vector<int>::iterator itr ;
        for (itr=vec.begin(); itr<vec.end(); ++itr)
            cin >> *itr ;
        sort(vec.begin(), vec.end());
        for (itr=vec.begin(); itr< vec.end(); ++itr){
            ans += count_if(vec.begin(), itr , compare(*itr));
        }
        cout << ans << '\n' ;
    }
}