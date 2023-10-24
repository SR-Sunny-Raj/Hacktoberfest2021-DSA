// Wave Sort
#include <bits/stdc++.h>
using namespace std;

void waveSort(int ar[], int n) {

	for (int i = 0; i < n; i += 2) {
		// check prev element
		if (i != 0 and ar[i] < ar[i - 1]) {
			swap(ar[i], ar[i - 1]);
		}
		// check next element
		if (i != n - 1 and ar[i] < ar[i + 1]) {
			swap(ar[i], ar[i + 1]);
		}
	}
}

int main() {

	int ar[] = {1, 3, 7, 16, 11, 15, 9, 8, 0};
	int n = sizeof(ar) / sizeof(ar[0]);
	waveSort(ar, n);

	for (int i = 0; i < n; ++i) {
		cout << ar[i] << " ";
	}

	return 0;
}
