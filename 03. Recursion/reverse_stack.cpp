#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
void insertatbottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int topele = st.top();
    st.pop();
    insertatbottom(st, ele);
    st.push(topele);
}
void reverse(stack<int> &st)
{
    if (st.empty())
        return;
    int ele = st.top();
    st.pop();
    reverse(st);
    insertatbottom(st, ele);
}
int32_t main()
{

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cerr
        << "processor time: " << clock() / (double)CLOCKS_PER_SEC << "s    ";

    return 0;
}