/* -------------------------------------------------------------------------- */
/*                 Add Natural Numbers Problem Code: ADDNATRL                 */
/* -------------------------------------------------------------------------- */

/**You are given a number N. Find the sum of all numbers from 1 to N.
*/

/*
Input:
    First-line will contain the number N.

Output:
    Print the answer in a single line.

Constraints
    1≤N≤109

Sample Input 1:
    4

Sample Output 1:
    10

Sample Input 2:
    8

Sample Output 2:
    36

EXPLANATION:
    In the first example, (1 + 2 + 3 + 4) = 10.
    In the second example, (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8) = 36.
*/

#include <iostream>
using namespace std;

int main()
{
    long int N, R; //10^9
    cin >> N;
    R = (N / 2) * (2 + (N - 1));
    cout << R;
    return 0;
}