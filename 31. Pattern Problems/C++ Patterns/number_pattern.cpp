#include <iostream>
using namespace std;
int main()
{
int n, x, y, k;
cout << "Enter the number of rows to show number paatern: ";
cin >> n;
for(x = 1; x <= n; x++)
{
for(y = x; y <n; y++)
{
cout << " ";
}
for(k = 1; k < (x*2); k++)
{
cout << k;
}
cout << "\n";
}
for(x = 4; x >= 1; x--)
{
for(y = n; y >  x; y--)
{
cout << " ";
}
for(k = 1; k < (x*2); k++)
{
cout << k;
}
cout << "\n";
}
return 0;
}
