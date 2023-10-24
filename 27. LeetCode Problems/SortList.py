// Problem Statement :- https://leetcode.com/problems/sort-list/

class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
#         creating a list
        l=[]
#     iterating the list
        while(head):
            l.append(head.val)
            head=head.next
#       sorting the list
        l.sort()
#          creating a new listNode
        last=ListNode()
#      ans is that list
        ans=last
#    again iterating new list and adding to the ans list
        for i in l:
            first=ListNode(i)
            last.next=first
            last=last.next
        return(ans.next)