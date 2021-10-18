#include <iostream>
using namespace std;

int main()
{
    int n; // no. of dominoes
    int sumx = 0, sumy = 0, c = 0;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        sumx += x[i];
        sumy += y[i];
        if ((x[i] + y[i]) % 2 != 0)
            c++;
    }
    if (sumx % 2 == 0 && sumy % 2 == 0)
        cout << 0 << endl;
    else if ((sumx + sumy) % 2 != 0)
        cout << -1 << endl;
    else if (c > 0)
        cout << 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}