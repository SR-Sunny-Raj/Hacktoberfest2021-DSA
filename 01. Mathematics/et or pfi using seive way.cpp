#include <bits/stdc++.h>
using namespace std;
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const long int MAX = 100;
    int etf[MAX + 1];
    for(int i=0;i<=MAX;i++)
        etf[i] = i;
    for(int i=2;i*i<=MAX;i++)
    {
        if(etf[i]== i)
        {
            for(long int j = i; j<=MAX ; j+=i)
            {
                etf[j] -= etf[j]/i;
            }
        }

    }
    for(int i=1;i<=25;i++)
        cout<<"  "<<i<<"  "<<etf[i]<<"  ";

    return 0;
}
