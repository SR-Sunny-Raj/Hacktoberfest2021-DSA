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
    
    ListNode *merge(ListNode*l1 , ListNode *l2)
    {
        ListNode *dm = new ListNode(-1);
        ListNode *curr=dm;
        
        while(l1 || l2)
        {
            if(l1== NULL)
            {
                curr->next = l2;
                return dm->next;
            }
            if(l2 == NULL){
                curr->next=l1;
                return dm->next;
            }
            if(l1->val < l2->val)
            {
                curr->next= l1;
                l1=l1->next;
            }
            else
            {
                curr->next = l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        return dm->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()== 0)
            return NULL;
        ListNode *head = lists[0];
        for(int i=1;i< lists.size();i++)
        {
            head = merge(head , lists[i]);
        }
        return head;
    }
};

