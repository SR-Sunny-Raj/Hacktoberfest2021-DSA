#include<iostream>
using namespace std;

//Progeam to print fibonacci series using  "Direct Recursion"

int fabionci(int n)
{
	if (n == 0)
	{
		return n;
	}
	else if (n == 1)
	{
		return n;
	}
	else
		return (fabionci(n - 1) + fabionci(n - 2)); 
	 
}

int main()
{
	cout << "How many fibionci number you want to print : ";
	int v;
	cin >> v;
	for (int i = 0; i < v; i++)
	{		cout << "\n" << fabionci(i);
}
	return 0;
}
