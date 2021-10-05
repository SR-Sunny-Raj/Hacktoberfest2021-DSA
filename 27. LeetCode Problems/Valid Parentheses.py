class Solution:
    def isValid(self, s: str) -> bool:
        dic ={'[':']', '{':'}', '(':')'}
        stack =[]
        for i in s:
            if len(stack) and dic.get(stack[-1]) ==i:
                stack.pop()
            else:
                    stack.append(i)
        return False if len(stack) else True
                
        
