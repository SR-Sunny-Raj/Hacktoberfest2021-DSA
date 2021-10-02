import math
class Solution:
    def countSetBits(self,n):
        # code here
        count=0
        if n==0:
            return 0
        else:
            x = math.floor(math.log(n,2))
            count += ((2**(x-1))*(x)) + (n-2**x) + 1 + self.countSetBits(n-2**x)
            return int(count)
if __name__ == "__main__":
    for _ in range(int(input())):
        ob = Solution()
        print(ob.countSetBits(int(input())))
