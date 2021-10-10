// C++ program of finding modulo multiplication
#include<bits/stdc++.h>

using namespace std;

// Returns (a * b) % mod
long long moduloMultiplication(long long a,
                               long long b,
                               long long mod)
{
	long long res = 0; // Initialize result

	// Update a if it is more than
	// or equal to mod
	a %= mod;

	while (b)
	{
		// If b is odd, add a with result
		if (b & 1)
			res = (res + a) % mod;

		// Here we assume that doing 2*a
		// doesn't cause overflow
		a = (2 * a) % mod;

		b >>= 1; // b = b / 2
	}

	return res;
}

// Driver program
int main()
{
	long long a = 10123465234878998;
	long long b = 65746311545646431;
	long long m = 10005412336548794;
	cout << moduloMultiplication(a, b, m);
	return 0;
}

// This code is contributed
// by Akanksha Rai
