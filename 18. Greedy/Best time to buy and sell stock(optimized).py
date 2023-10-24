from typing import List
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        for pos in range(len(prices)):
            if prices[pos] > prices[pos-1]:
                prices += prices[pos] - prices[pos-1]
        return profit
