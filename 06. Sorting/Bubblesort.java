
//Code for Bubble sort algorithm in Java
import java.io.*;

class Bubblesort {
    
    static void bubbleSort(int arr[], int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i - 1; j++){
                if( arr[j] > arr[j + 1]){
                    
                    // swapping
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    
                }
            }
        }
    }
    
	public static void main (String[] args) {
	    int a[] = {2, 1, 4, 3};
	    bubbleSort(a, 4);
	    
	    for(int i = 0; i < 4; i++){
	        System.out.print(a[i] + " ");
	    }
	}
}
