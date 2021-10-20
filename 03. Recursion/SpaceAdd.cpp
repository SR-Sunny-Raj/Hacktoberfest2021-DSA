#include <iostream>
using namespace std;
// I/P = "ABC"
/* O/P = "ABC" "AB C" "A BC" "A B C"*/
void solve(string s, int n)
{
    if (n == 1)
    {
        cout <<'"'<< s <<'"'<< ", ";
        return;
    }
    string s1 = s;
    string s2 = s;
    s2.insert(--n, " ");
    solve(s1, n);
    solve(s2, n);
}
int main()
{
    string s;
    cout<<"Enter String: ";
    cin >> s;
    solve(s, s.length());
    return 0;
}