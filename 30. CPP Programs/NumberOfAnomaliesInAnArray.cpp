#include <bits/stdc++.h>
using namespace std;
int getAnomaliesCount(int arr[], int n, int k) {
   int count = 0;
   for (int i = 0; i < n; i++) {
      int j;
      for (j = 0; j < n; j++) {
         if (i != j && abs(arr[i] - arr[j]) <= k) {
            break;
         }
      }
      if (j == n) {
         count++;
      }
   }
   return count;
}
int main() {
   int arr[] = {3, 1, 5, 7}, k = 1;
   int n = 4;
   cout << getAnomaliesCount(arr, n, k) << endl;
   return 0;
}