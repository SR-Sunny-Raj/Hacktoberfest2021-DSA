// Reverse a stack in O(1) space
#include<bits/stdc++.h>
#define ll long long int
#define input(type, a) type a; cin>>a
#define v(type) vector<type>
#define PB push_back
#define PF push_front
#define emp emplace
#define m_p make_pair
#define deq(type) deque<type>
#define tests ll t; cin >> t; while(t--)
#define FOR(iter,a,b) for(int iter = a;iter<b;iter++)
using namespace std;

void insertAtBottom(stack<int> &st, int top){
    if(st.empty()==true){
        st.push(top);
        return;
    }
    int top_ele = st.top();
    st.pop();
    insertAtBottom(st, top);
    st.push(top_ele);
    return;
}

void reverse(stack<int> &st){

    if(st.empty() || st.size()==1){
        return;
    }

    int top = st.top();
    st.pop();

    reverse(st);

    insertAtBottom(st, top);
    // cout<<"Reversing ";
    return;

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st);
    cout<<"Printing reverse order"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";st.pop();
    }

    return 0;
}
