#include <iostream>
using namespace std;

void is_palin(string str, int n)
{

    string tempStr = str;

    int i = 0, j = n - 1;

    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    if (str == tempStr)
    {
        cout << "Its palindrome" << endl;
    }
    else
    {
        cout << " Not palindrome" << endl;
    }
}

int main()
{

    string str;
    getline(cin, str);
    int n = str.length();

    is_palin(str, n);

    return 0;
}