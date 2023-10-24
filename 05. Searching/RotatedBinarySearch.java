package com.firsts;
//Takes a Rotated and Increasing Sorted array, a target and returns its index
public class RotatedArray {
    static int rotatedBinarySearch(int[] arr,int target){
        int pivot = findPivot(arr);
        if(pivot == -1)
            return binarySearch(arr,target,0,arr.length - 1);
        else if(target == arr[pivot])
            return pivot;
        else if (target >= arr[0])//if the target is greater than arr[0],target lies in the left portion of the pivot
            return binarySearch(arr,target,0,pivot - 1);
        return binarySearch(arr,target,pivot + 1,arr.length - 1);//else right portion of the pivot
    }
    /*Pivot is the peak element in the rotated sorted array and last element in its original sorted array
    All the elements left to the pivot are increasingly sorted ,pivot and pivot + 1 are dec sorted
     and pivot + 1 to last index are increasingly sorted again*/
    /*Since pivot is the last index of the original array,in rot sorted array all the elements left to the pivot
    are always greater than all the elements right to the pivot*/
    static int findPivot(int[] arr){
        int start = 0;
        int end = arr.length - 1;
        while(start < end){
            int mid = start + (end - start) / 2;
            if(arr[mid] > arr[mid + 1])
                return mid; //return mid, if mid is on the pivot index
            if(arr[mid] < arr[mid - 1])
                return mid - 1; // return mid - 1,if mid is on the pivot + 1 index
            if(arr[start] < arr[mid])
                start = mid + 1; // mid is on the left side of the pivot and left portion(start to mid)is sorted
            else
                end = mid - 1;//mid is on the right side ,so we move to the left of mid
        }
        return -1;//return -1 if pivot is not found (case of strictly inc array)
    }
    static int binarySearch(int[] arr,int target,int start,int end){
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(target > arr[mid])
                start = mid + 1;
            else if (target < arr[mid])
                end = mid - 1;
            else
                return mid;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {10,12,15,18,19,1,3,4,5,6,7,8};
        int target = 15;
        System.out.println(rotatedBinarySearch(arr,target));
    }
}

