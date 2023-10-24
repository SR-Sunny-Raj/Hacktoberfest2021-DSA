public class BinarySearchInJava {
    public static void main(String[] args) {
        int[] arr= { 1,2,3,4,5,6,7,9,12,14,16,18,19,23};
        int target = 1;
        System.out.println(binarySearch(arr,target));
    }
    public static int binarySearch(int nums[], int target)
    {
        int left=0;
        int right= nums.length-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return mid;
            else if(target>nums[mid]) left=mid+1;
            else if(target<nums[mid]) right=mid-1;
         }
        return -1;
    }
}
