import java.util.Scanner;

public class BubbleSort { 
    public static void main(String[] args) {
        BubbleSort bubbleSort = new BubbleSort();
        Scanner sc = new Scanner(System.in);
        int total;
        
        System.out.println("\n==== Bubble Sort ====\n");

        System.out.print("Enter the amount numbers you want to sort : ");
        total = sc.nextInt();
        int[] arr = new int[total];

        System.out.println();
        for(int i=0; i<total; i++) {
            System.out.print("Enter number-" + (i+1) + " : ");
            arr[i] = sc.nextInt();
        }

        bubbleSort.sort(arr);

        System.out.println("\nResult :");
        for(int i=0; i<total; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public void sort(int[] arr) {
        for (int i = 0; i < (arr.length - 1); i++) {
            for (int j = 0; j < (arr.length - i - 1); j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}
