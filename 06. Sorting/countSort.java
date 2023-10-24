import java.util.*;

public class code {

    public static int[] bSort(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];

        // Inputing the Array
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        sc.close();

        // Sorting
        arr = code.bSort(arr, n); // Creating an object of the class

        // Printing the Array
        System.out.println("New Array: ");
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }
}
