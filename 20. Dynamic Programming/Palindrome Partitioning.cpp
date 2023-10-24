// Dynamic Programming Solution for Palindrome Partitioning Problem
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int min(int a, int b) { return (a < b) ? a : b; }

int minPalPartion(char* str)
{

	int n = strlen(str);
	int C[n];
	bool P[n][n];

	int i, j, k, L; // different looping variables

	for (i = 0; i < n; i++) {
		P[i][i] = true;
	}

	for (L = 2; L <= n; L++) {
        for (i = 0; i < n - L + 1; i++) {
			j = i + L - 1; // Set ending index

			if (L == 2)
				P[i][j] = (str[i] == str[j]);
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
		}
	}

	for (i = 0; i < n; i++) {
		if (P[0][i] == true)
			C[i] = 0;
		else {
			C[i] = INT_MAX;
			for (j = 0; j < i; j++) {
				if (P[j + 1][i] == true && 1 + C[j] < C[i])
					C[i] = 1 + C[j];
			}
		}
	}

	return C[n - 1];
}

// Driver program to test above function
int main()
{
	char str[] = "ababbbabbababa";
	cout <<"Min cuts needed for Palindrome Partitioning is " << minPalPartion(str);
	return 0;
}
