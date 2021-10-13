#include <iostream>
using namespace std; 
int main()
{
    int i, j, n;
    cin >> n;
    // upper half of the pattern
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i >= j) // upper left triangle
                cout << "*";
            else
                cout << " ";
            if(i >= (2 * n - 1) - j)  // upper right triangle
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    // bottom half of the pattern
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < (2 * n); j++)
        {
            if(i + j <= n - 1)  // bottom left triangle
                cout << "*";
            else
                cout << " ";
            if((i + n) <= j)  // bottom right triangle
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
