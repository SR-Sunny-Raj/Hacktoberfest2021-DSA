#include <iostream>
#include <cmath>

using namespace std;

int BinToOct(long long);
int main()
{
    long long bin;

    cout << "Enter a binary number: ";
    cin >> bin;

    cout  << " in octal, " << bin << " = " << BinToOct(bin);

    return 0;
}

int BinToOct(long long bin)
{
    int octal = 0, decimal = 0, i = 0;

    while(bin != 0)
    {
        decimal += (bin%10) * pow(2,i);
        ++i;
        bin = bin/10;
    }

    i = 1;

    while (decimal != 0)
    {
        octal += (decimal % 8) * i;
        decimal = decimal/8;
        i = i*10;
    }

    return octal;
}
