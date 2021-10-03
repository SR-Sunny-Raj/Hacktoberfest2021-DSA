#include <bits/stdc++.h>
#include <stdint.h>

using namespace std ;

typedef vector<int>::iterator vi ;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, K, P ;
    cin >> N >> K >> P ;
    vector<int> vec(N+1), vec1(N) ; // 1 extra in vec to avoid array out of bounds
    map<int, int> v ; // Default order in a map is increasing order
    int temp ;
    for(int i=0; i<N; ++i) {
        cin >> temp ;
        vec[i] = temp ;
        v.insert(pair<int, int>(i + 1, temp));
    }
    vec[N] = INT32_MAX ;
    sort(vec.begin(), vec.end()) ;
    int i=0, j=0 ;
    for(; i<N; ++i) {
        for (j=max(j, i); j < N; ++j) {
            if (vec[j+1]-vec[j] > K){ // Problem of index out of bounds at i=N solved using infinity
                vec1[i] = j ;
                break ;
            }
        }
    }
    int A, B ;
    while(P--){
        cin >> A >> B ;
        vi h = lower_bound(vec.begin(), vec.end(), v[A]) ;
        vi g = lower_bound(vec.begin(), vec.end(), v[B]) ;
        vi l = *g>*h ? h : g; // l points to element with min value
        vi m = l==h ? g : h ;
        if (vec1[distance(vec.begin(), l)]>=distance(vec.begin(), m)){
            cout << "Yes\n" ;
        } else {
            cout << "No\n" ;
        }
    }
}