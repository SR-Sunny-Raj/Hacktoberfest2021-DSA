//Shell Sort


#include <iostream>
using namespace std;
int c;
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2,c++) {
    for (int i = interval; i < n; i += 1,c++) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval,c++) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++,c++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int data[100];
  int size;
  cout << "input size n"<<endl;
  cin >> size;
  for(int j=0;j<size;j++,c++)
  {
    cin >> data[j];
  }
  shellSort(data, size);
  cout << "Sorted array: \n";
  printArray(data, size);
   cout << "Step count:" << c / size << "n+ " << c % size << "\n";
   cout << "Stepcount:";
    if (c >= size * size)
    {
        cout << c / (size * size) << "n^2+ ";
        c = c % (size * size);
    }
    cout << c / size << "n+ " << c % size << "\n";
}
