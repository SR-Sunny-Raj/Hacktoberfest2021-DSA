class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        def binary_search(arr, target):
            low = 0
            high = len(arr)-1
            while low<=high:
                mid = low + (high-low)//2
                if arr[mid] == target:
                    return True
                elif arr[mid]<target:
                    low = mid+1
                else:
                    high = mid-1
                    
            return False
        
        if not matrix or not matrix[0]:
            return False
        
        rowlow = 0
        rowhigh = len(matrix)-1
        
        while rowlow <= rowhigh:
            mid = rowlow + (rowhigh-rowlow)//2
            
            if matrix[mid][0]<=target<=matrix[mid][-1]:
                return binary_search(matrix[mid], target)
            
            elif target < matrix[mid][0]:
                rowhigh = mid-1
            
            else:
                rowlow = mid+1
                
        return False