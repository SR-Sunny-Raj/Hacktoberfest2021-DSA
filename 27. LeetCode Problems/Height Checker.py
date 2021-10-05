# /*
#     Problem Link
#     https://leetcode.com/problems/find-the-highest-altitude/
# */

def heightChecker(heights):
    length = len(heights)
    expected = sorted(heights)
    
    count = 0
    
    for i in range(length):
        if expected[i] != heights[i]:
            count += 1
            
    return count

# Time Complexity : O(nlogn)
# Space Complexity : O(1)

