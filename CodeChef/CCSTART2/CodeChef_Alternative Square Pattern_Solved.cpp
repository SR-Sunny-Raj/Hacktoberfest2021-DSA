/* -------------------------------------------------------------------------- */
/*              Alternative Square Pattern Problem Code: SQALPAT              */
/* -------------------------------------------------------------------------- */

/**You're given a number N. Print the first N lines of the below-given pattern.

    1 2 3 4 5
    10 9 8 7 6
    11 12 13 14 15
    20 19 18 17 16
    21 22 23 24 25
    30 29 28 27 26
    
*/

/*
Input:
    First-line will contain the number N.

Output:
    Print the first N lines of the given pattern.

Constraints
    1≤N≤200

Sample Input 1:
    4

Sample Output 1:
    1 2 3 4 5
    10 9 8 7 6
    11 12 13 14 15
    20 19 18 17 16

Sample Input 2:
    2

Sample Output 2:
    1 2 3 4 5
    10 9 8 7 6

EXPLANATION:
    In the first example, we'll print the first 4 lines of the given pattern.
    In the second example, we'll print the first 2 lines of the given pattern.
*/

// #include <iostream>
// using namespace std;

// int main()
// {
//     int N, show, j = 1, k = 1;
//     cin >> N;
//     for (int i = 0; i < N; i++)
//     {
//         for (j = k; j <= (i + 1) * 5; j++)
//             cout << j << " ";
//         cout << endl;
//         for (k = (i + 2) * 5; k >= j; k--)
//             cout << k << " ";
//         cout << endl;
//     }
//     cin >> show;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int N, j = 1, k;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 1 || i == 1)
        {
            for (; j <= i * 5; j++)
                cout << j << " ";
            cout << endl;
        }
        else
        {
            for (int k = i * 5; k >= j; k--)
                cout << k << " ";
            cout << endl;
        }
        j = (i*5)+1;
    }
    return 0;
}