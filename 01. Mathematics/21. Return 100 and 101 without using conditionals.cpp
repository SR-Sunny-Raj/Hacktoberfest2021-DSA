/* Important Interview Question */
// Write a function that returns 101 if 100 is passed as a parameter and returns 100 if 101 passed as a parameter.
// You are not allowed to use any conditionals.

#include <iostream>

using namespace std;

int number(int num) {
    return 201 - num;
}

int main()
{
    cout << number(100) << endl;
    cout << number(101) << endl;

    return 0;
}

