// Java program for Fibonacci Search
import java.util.*;

class Fibonacci {
	// Utility function to find minimum of two elements
	public static int min(int a, int y)
	{
		return (a <= y) ? a : y;
	}

	/* Returns index of a if present, else returns -1 */
	public static int fibMonaccianSearch(int arr[], int a,
										int num)
	{
		/* Initialize fibonacci numbers */
		int fibMMm2 = 0; // (m-2)'th Fibonacci No.
		int fibMMm1 = 1; // (m-1)'th Fibonacci No.
		int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

		/* fibM is going to store the smallest Fibonacci Number greater than or equal to num */
		while (fibM < num) {
			fibMMm2 = fibMMm1;
			fibMMm1 = fibM;
			fibM = fibMMm2 + fibMMm1;
		}

		// Marks the eliminated range from front
		int offset = -1;

		/* while there are elements to be inspected. Note that we compare arr[fibMm2] with a. When fibM becomes 1, fibMm2 becomes 0 */
		while (fibM > 1) {
			// Check if fibMm2 is a valid location
			int i = min(offset + fibMMm2, num - 1);

			/* If a is greater than the value at index fibMm2, cut the subarray array from offset to i */
			if (arr[i] < a) {
				fibM = fibMMm1;
				fibMMm1 = fibMMm2;
				fibMMm2 = fibM - fibMMm1;
				offset = i;
			}

			/* If a is less than the value at index fibMm2, cut the subarray after i+1 */
			else if (arr[i] > a) {
				fibM = fibMMm2;
				fibMMm1 = fibMMm1 - fibMMm2;
				fibMMm2 = fibM - fibMMm1;
			}

			/* element found. return index */
			else
				return i;
		}

		/* comparing the last element with a */
		if (fibMMm1 == 1 && arr[num-1] == a)
			return num-1;

		/*element not found. return -1 */
		return -1;
	}

	// driver code
	public static void main(String[] args)
	{
		int arr[] = { 10, 22, 35, 40, 45, 50,
					80, 82, 85, 90, 100,235};
		int num = 12;
		int a = 235;
	int ind = fibMonaccianSearch(arr, a, num);
		if(ind>=0)
		System.out.print("Found at index: " +ind);
	else
		System.out.print(a+" isn't present in the array");
	}
}

