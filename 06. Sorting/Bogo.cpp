// Bogo Sort

#include<bits/stdc++.h>
using namespace std;

bool checkSorted(int* arr, int n) {
    while(--n > 1)
        if(arr[n] < arr[n-1])
            return false;
    return true;
}

void shuffle(int* arr, int n) {
    for(int i = 0; i < n; i++)
        swap(arr[i], arr[rand()%n]);
}

void bogoSort(int* arr, int n) {
    while(!checkSorted(arr, n))
        shuffle(arr, n);
}

void printSorted(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "\nGiven Array:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bogoSort(arr, n+1);

    cout << "\nSorted Array:\n";
    printSorted(arr, n);
}