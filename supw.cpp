#include <bits/stdc++.h>

using namespace std;

int main(){

    // The next 2 lines speedened up the code by a factor of 4
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);


    int N ;
    cin >> N ;
    vector<int> work(N) ;
    vector<int> v(N) ;
    for(int i=0; i<N; ++i)
        cin >> work[i] ;
    copy(work.begin(), work.end(), v.begin()) ;
    for(int i=3; i<N; ++i ){
        v[i] += min(min(v[i-1], v[i-2]), v[i-3]) ;
    }
    if (N<3){
        cout << *min_element(v.begin(), v.end()) ;
        exit(0) ;
    }
    cout << *min_element(v.end()-3, v.end()) ;
}