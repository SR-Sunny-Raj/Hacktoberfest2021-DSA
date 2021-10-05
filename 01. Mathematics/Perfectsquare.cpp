#include <bits/stdc++.h>
using namespace std;
bool perfectsquare(int x)
{
    float temp = sqrt(x);
    if (ceil(temp) == floor(temp))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int x;
    cin >> x;
    if (perfectsquare(x))
    {
        cout << "perfectsquare" << endl;
    }
    else
    {
        cout << "not perfectsquare" << endl;
    }
}
