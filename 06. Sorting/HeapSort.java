import java.util.*;
public class HeapSort {
	// A function to create Max-Heap.....Takes O(nlogn) time at maximum for creation...
	public void createMaxHeap(int arr[], int heap[], int heapSize, int n) {
		// Inserting first element is always at max heap...
		heap[0] = arr[0];
		heapSize++;
		for(int i=1;i<n;i++) {
			heap[i] = arr[i];
			int j = i;
			while(j>0) {
				// parent of node i is at i/2....
				if(heap[j/2]<heap[j]) 
					// If the value of parent is less than its child, then swap child with parent...
					swap(heap,j,j/2);
				j = j/2;
			}
			heapSize++;
		}
		System.out.println("Max Heap is: "+Arrays.toString(heap));
		System.out.println("Heap Size is: "+heapSize);
	}
	
	public void heapSort(int heap[],int heapSize) {
		while(heapSize!=0) {
			// extract the root of the max heap... and append to end of heap(as this element is not part of heap now)
			int root = heap[0];
			// bring the last element of heap to the root and max-heapify...
			heap[0] = heap[heapSize-1];
			heap[heapSize-1] = root;
			heapSize--;
			// start heapifying from root and swapping the larger value of its child....
			int i = 0;
			int left = 2*i+1;
			int right = 2*i+2;
			while(i<heapSize && (left<heapSize || right<heapSize)){
				if(left>=heapSize && right<heapSize) {
					if(heap[right]>heap[i]) 
						swap(heap,right,i);
					else 
						break;
					i = right;
				}
				else if(left<heapSize && right>=heapSize) {
					if(heap[left]>heap[i]) 
						swap(heap,left,i);
					else 
						break;
					i = left;
				}
				else if(heap[left]>heap[right]) {
					if(heap[left]>heap[i]) 
						swap(heap,left,i);
					else 
						break;
					i = left;
				} 
				else if(heap[right]>heap[left]) {
					if(heap[right]>heap[i]) 
						swap(heap,right,i);
					else 
						break;
					i = right;
				}
				left = 2*i+1;
				right = 2*i+2;
			}
		}
		System.out.println("Heap after sorting is: "+Arrays.toString(heap)+"\n");
	}
	
	public void swap(int arr[], int f, int s) {
		int temp = arr[f];
		arr[f] = arr[s];
		arr[s] = temp;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("\t\tHEAP SORT ALGORITHM\n");
		System.out.printf("Enter number of elements: ");
		int n = sc.nextInt();
		System.out.println("Enter array elements to be sorted: ");
		int arr[] = new int[n];
		for(int i=0;i<n;i++)
			arr[i] = sc.nextInt();
		int heap[] = new int[n];
		HeapSort hp = new HeapSort();
		hp.createMaxHeap(arr, heap, 0, n);
		hp.heapSort(heap, n);
		sc.close();
	}

}
