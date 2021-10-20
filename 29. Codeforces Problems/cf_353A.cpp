/*Valera has got n domino pieces in a row. Each piece consists of two halves — the upper one and the lower one. Each of the halves
contains a number from 1 to 6. Valera loves even integers very much, so he wants the sum of the numbers on the upper halves and the
sum of the numbers on the lower halves to be even.

To do that, Valera can rotate the dominoes by 180 degrees. After the rotation the upper and the lower halves swap places. This action
takes one second. Help Valera find out the minimum time he must spend rotating dominoes to make his wish come true.

Input
The first line contains integer n (1 ≤ n ≤ 100), denoting the number of dominoes Valera has. Next n lines contain two space-separated
integers xi, yi (1 ≤ xi, yi ≤ 6). Number xi is initially written on the upper half of the i-th domino, yi is initially written on the
lower half.

Output
Print a single number — the minimum required number of seconds. If Valera can't do the task in any time, print  - 1.
*/
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
