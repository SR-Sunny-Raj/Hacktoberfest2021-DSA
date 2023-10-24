#include <bits/stdc++.h>
using namespace std;

// Returns value of Binomial Coefficient
int binomialCoefficient(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    // Recurrence Relation
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

/* Driver code to test program*/
int main()
{
    int n = 5, k = 2;
    cout << n << "C" << k << " is "<< binomialCoefficient(n, k);
    return 0;
}

