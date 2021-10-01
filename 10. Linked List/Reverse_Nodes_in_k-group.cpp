/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int countlength(ListNode* head)
    {
        int count= 0;
        ListNode* temp= head;
        while(temp!= NULL)
        {
            temp= temp-> next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==0)
        {
            return head;
        }
        int count= 0;
        ListNode* curr= head;
        ListNode* next= NULL;
        ListNode* prev= NULL;
        while(curr!= NULL && count< k)
        {
            next= curr-> next;
            curr-> next= prev;
            prev= curr;
            curr= next;
            count++;
        }
        if(countlength(next)< k)
        {
            head-> next= curr;
        }
        else
        {
            head-> next= reverseKGroup(curr, k);
        }
        return prev;
    }
};
