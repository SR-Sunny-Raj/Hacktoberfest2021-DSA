#include<bits/stdc++.h>
using namespace std;

void push(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != 0)
			a[count++] = a[i];
	while (count < n)
		a[count++] = 0;
}

int main()
{
	int a[] = {1, 0, 2, 4, 6, 0, 3, 9, 0, 5, 0, 7};
	int n = sizeof(a) / sizeof(a[0]);
	push(a, n);
	cout << "After Pushing at end :\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}

