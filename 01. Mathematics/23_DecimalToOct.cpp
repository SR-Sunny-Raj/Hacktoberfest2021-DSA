#include <iostream>
#include <cmath>
using namespace std;

int DecToOct(int Decimal);

int main()
{
   int Decimal;
   cout << "Enter a decimal number: ";
   cin >> Decimal;
   cout << Decimal << " in octal = " << DecToOct(Decimal);

   return 0;
}


int DecToOct(int Decimal)
{
    int rem, i = 1, Octal = 0;
    while (Decimal != 0)
    {
        rem = Decimal % 8;
        Decimal /= 8;
        Octal += rem * i;
        i *= 10;
    }
    return Octal;
}
