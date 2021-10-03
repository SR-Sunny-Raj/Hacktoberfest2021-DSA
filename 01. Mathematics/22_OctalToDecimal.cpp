#include <iostream>
#include <cmath>
using namespace std;

int OctToDec(int Octal);

int main()
{
   int Octal;
   cout << "Enter an octal number: ";
   cin >> Octal;
   cout << Octal << " in decimal " <<" = "<< OctToDec(Octal);

   return 0;
}


int OctToDec(int Octal)
{
    int Decimal = 0, i = 0, rem;
    while (Octal!=0)
    {
        rem = Octal%10;
        Octal = Octal/10;
        Decimal += rem * pow(8, i);
        ++i;
    }
    return Decimal;
}
