// Problem link - https://codeforces.com/contest/1579/problem/E2

// Let's process the array elements one by one.
// For the first element, it doesn't matter which side of the deque we add it to, the result of its addition will be the same — 
// there will be a sequence of one element (equal to the first array element) in the deque.
// Now let's consider adding the ith element of an array into the deck. First i=2 will be considered, then i=3, and so on up to i=n.
// Let us describe the general algorithm for choosing the side of the dec for each step. Note that if the elements [d1,…,di−1] now lie in the deck, then all final sequences that can be obtained in the deck from the current state can be broken down into pairs of the form
// […,ai,d1,…,di−1,…]
// […,d1,…,di−1,ai,…],
// Note that since the prefix and suffix hidden behind the dots completely coincide in the two sequences under consideration, as well as the set of numbers in the central part coincides, the numbers of inversions also coincide:
// inside the prefix and inside the suffix;
// between elements of the prefix and elements of the suffix;
// between elements of the prefix or suffix and elements of the central part.
// The difference between the number of inversions in the first and second sequence consists only of the difference between the number of inversions in their central part. So, we can determine at the stage of adding ai to the deque, which direction of its addition is guaranteed not to lead to the optimal answer and choose the opposite one.
// If ai is added to the beginning of the deque, the number of inversions in the central part will increase by the number of elements in the deque strictly smaller than ai, and if we add it to the end of the deque, it will increase by the number of elements in the deque strictly larger than ai. Let us make a choice such that the number of inversions increases by the minimum of these two values.
// To quickly find the number of elements smaller or larger than ai, we will store all already processed array elements in a structure that supports the element order search operation, such as __gnu_pbds::tree.

// Requests to update and get an order in such structures take O(logn) time, and the construction takes at worst O(nlogn), so the time complexity of the algorithm is O(nlogn).
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef long long int ll;
using namespace __gnu_pbds;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
int main(void){
    ll t;
    cin>>t;
    while(t--){
        ll n,i;
        cin>>n;
        vector<ll> v(n);
        for(i=0;i<n;i++){
            cin>>v[i];
        }
        ordered_multiset s;
        ll ans=0;
        s.insert(v[0]);
        map<ll,ll> m;
        m[v[0]]++;
        for(i=1;i<n;i++){
            ll x=s.order_of_key(v[i]);
            ll y=i-x-m[v[i]];
            ans+=min(x,y);
            s.insert(v[i]);
            m[v[i]]++;
        }
        cout<<ans<<endl;
    }
}