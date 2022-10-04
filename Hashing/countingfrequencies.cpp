#include <bits/stdc++.h>
using namespace std;

void CountFreq(int arr[], int n) // function to count the frequency of the element
{
  unordered_map<int, int> h;
  for (int i = 0; i < n; i++)
  {
    h[arr[i]]++;
  }
  for (auto e : h)
  {
    cout << e.first << " " << e.second << endl;
  }
}

int main()
{
  int n; // size of the array
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  CountFreq(arr, n);
  return 0;
}