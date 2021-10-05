// C++ program to calculate pow(x,n)
#include <iostream>
using namespace std;
class gfg
{

public:
    int power(int x, unsigned int y)
    {
        if (y == 0)
            return 1;
        else if (y % 2 == 0)
            return power(x, y / 2) * power(x, y / 2);
        else
            return x * power(x, y / 2) * power(x, y / 2);
    }
};

int main()
{
    gfg g;
    int x = 2;
    unsigned int y = 3;

    cout << g.power(x, y);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)