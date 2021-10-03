/* Given the head of a singly linked list, return true if it is a palindrome.

Input: head = [1,2,2,1]
Output: true

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *l = head;
        ListNode *r = head;
        ListNode *prev = NULL;
        ListNode *tmp;
        while(r!=NULL && r->next!=NULL)
        {
            r = r->next->next;
            tmp = l->next;
            l->next = prev; //reversing the list before mid section ad storing in prev
            prev = l;
            l = tmp;
        }
        if(r!=NULL)
        {
            l = l->next;    //if length of list is odd then we neglect the mid element
        }
        while(prev!=NULL && l!=NULL)
        {
            if(prev->val==l->val)
            {
                prev=prev->next;    //now checking 
                l=l->next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};