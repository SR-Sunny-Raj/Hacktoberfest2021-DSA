#include <iostream>
using namespace std;
int power(int x, unsigned int y, int p)
{
	int res = 1;

	x = x % p;

	if (x == 0) return 0;

	while (y > 0)
	{

		if (y & 1)
			res = (res * x) % p;


		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

int main()
{
	int x = 2;
	int y = 5;
	int p = 13;
	cout << "Power is " << power(x, y, p);
	return 0;
}

