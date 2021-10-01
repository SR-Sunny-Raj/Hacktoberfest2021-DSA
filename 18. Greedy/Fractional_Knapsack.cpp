/* 
Given weights and values of n items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

In the 0-1 Knapsack problem, we are not allowed to break items. We either take the whole item or don’t take it. 
Input: 
Items as (value, weight) pairs 
arr[] = {{60, 10}, {100, 20}, {120, 30}} 
Knapsack Capacity, W = 50; 

Output: 
Maximum possible value = 240 
by taking items of weight 10 and 20 kg and 2/3 fraction 
of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240
*/





#include <bits/stdc++.h>

using namespace std;

struct Item {
	int value, weight;

	Item(int value, int weight)
	{
	this->value=value;
	this->weight=weight;
	}
};

bool cmpt(struct Item a, struct Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}


double fractionalKnapsack(int W, struct Item arr[], int n)
{
	// sorting Item on basis of ratio
	sort(arr, arr + n, cmpt);


	int curWeight = 0; // Current weight in knapsack
	double finalvalue = 0.0; // Result (value in Knapsack)

	// Looping through all Items
	for (int i = 0; i < n; i++) {
	                                     	// If adding Item won't overflow, add it completely
		if (curWeight + arr[i].weight <= W)
    {
			curWeight += arr[i].weight;
			finalvalue += arr[i].value;
		}

		else
    {
			int remain = W - curWeight;
			finalvalue += arr[i].value	* ((double)remain	/ (double)arr[i].weight);
			break;
		}
	}

  
	return finalvalue;
}

// Driver code
int main()
{
	int W = 50; // Weight of knapsack
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << "Maximum value we can obtain = "
		<< fractionalKnapsack(W, arr, n);
	return 0;
}

