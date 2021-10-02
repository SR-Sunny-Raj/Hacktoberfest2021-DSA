// package DSA;

public class dsa3_Floar {
    public static void main(String[] args) {
        int[] arr = {1,3,5,7,9,12,14,15,17,29,34,37,46,58,100};
        int target = 0;
        FindAns(arr, target);
    }
    static void FindAns(int[] arr, int target){
        int start = 0;
        int end = arr.length-1;
        int mid=0;
        
        while(start<=end){
            mid = start + (end - start)/2;
            if(target>arr[arr.length-1]){
                System.out.println("Target element: '" + target + "' is not found so its celing is: " + arr[arr.length-1] + " at index: " + (arr.length-1));
                System.exit(0);
            }
            else if(target < arr[0]){
                System.out.println("No smaller element than: " + target);
                System.out.println("Smallest element in array is: " + arr[0]);
                break;
            }
            else if(target > arr[mid]){
                start = mid+1;
            }
            else if(target < arr[mid]){
                end = mid-1;
            }
            else{
                System.out.println("Target element '" + target + "' is at index: " + mid);
                break;
            }
        }
        if(target != arr[mid]){
            System.out.println("Target element '" + target + "' is not found so its celing is: " + arr[mid-1] + " at index: " + (mid-1));
        }
    }
}
