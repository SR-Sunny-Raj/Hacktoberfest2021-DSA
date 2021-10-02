#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      if (array[i] < array[min_idx])
        min_idx = i;
    }

    swap(&array[min_idx], &array[step]);
  }
}

int main() {
  int array1[] = {20, 12, 10, 15, 2};
  int size = sizeof(array1) / sizeof(array1[0]);
  selectionSort(array1, size);
  cout << "Sorted array in Acsending Order:\n";
  printArray(array1, size);
  return 0;
}
