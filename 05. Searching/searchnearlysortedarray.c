#include <stdio.h>
 

int searchElement(int nums[], int n, int target)
{
    
    int low = 0, high = n - 1;
 
    while (low <= high)
    {
        int mid = (low + high) / 2;
 
        if (nums[mid] == target) {
            return mid;
        }
 
        else if (mid - 1 >= low && nums[mid - 1] == target) {
            return mid - 1;
        }
 
        else if (mid + 1 <= high && nums[mid + 1] == target) {
            return mid + 1;
        }

        else if (target > nums[mid]) {
            low = mid + 2;
        }

        else {
            high = mid - 2;
        }
    }

    return -1;
}
 
int main(void)
{
    int nums[] = { 2, 1, 3, 5, 4, 7, 6, 8, 9 };
    int target = 5;
 
    int n = sizeof(nums) / sizeof(nums[0]);
    int index = searchElement(nums, n, target);
 
    if (index != -1) {
        printf("Element %d found at index %d", target, index);
    }
    else {
        printf("Element not found in the array");
    }
 
    return 0;
}