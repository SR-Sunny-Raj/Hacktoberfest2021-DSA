#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the minimum number of coins required
// to get a total of `target` from set `S`
int findMinCoins(vector<int> const &S, int target)
{
    // if the total is 0, no coins are needed
    if (target == 0)
    {
        return 0;
    }

    // return infinity if total becomes negative
    if (target < 0)
    {
        return INT_MAX;
    }

    // initialize the minimum number of coins needed to infinity
    int coins = INT_MAX;

    // do for each coin
    for (int i : S)
    {
        // recur to see if total can be reached by including current coin `i`
        int result = findMinCoins(S, target - i);

        // update the minimum number of coins needed if choosing the current
        // coin resulted in a solution
        if (result != INT_MAX)
        {
            coins = min(coins, result + 1);
        }
    }

    // return the minimum number of coins needed
    return coins;
}

int main()
{
    // coins of given denominations
    vector<int> S = {1, 2, 3, 4};

    // total change required
    int target = 15;

    int coins = findMinCoins(S, target);
    if (coins != INT_MAX)
    {
        cout << "The minimum number of coins required to get the desired change is "
             << coins;
    }

    return 0;
}