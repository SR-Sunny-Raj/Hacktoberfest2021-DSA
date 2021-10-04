 def solution(arr, start):
    memo = {}
    return dfs(arr, start, memo)

def dfs(arr, i, memo):
    if i < 0 or i >= len(arr):
        return False 
    if arr[i] == 0:
        return True
    if i in memo:
        return memo[i]
    memo[i] = False 
    if dfs(arr, i - arr[i], memo):
        return True
    if dfs(arr, i + arr[i], memo):
        return True
    return False
