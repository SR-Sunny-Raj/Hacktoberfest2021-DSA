// C++ Program to implement
// the above approach
#include <iostream>
using namespace std;

// Function to return a^n
int powerOptimised(int a, int n)
{

    // Stores final answer
    int ans = 1;

    while (n > 0)
    {

        int last_bit = (n & 1);

        // Check if current LSB
        // is set
        if (last_bit)
        {
            ans = ans * a;
        }

        a = a * a;

        // Right shift
        n = n >> 1;
    }

    return ans;
}

// Driver Code
int main()
{
    int a = 3, n = 5;

    cout << powerOptimised(a, n);

    return 0;
}