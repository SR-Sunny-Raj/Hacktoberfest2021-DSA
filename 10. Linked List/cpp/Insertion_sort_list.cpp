/* 
Question: Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

Example:
I/O : [4, 2, 1, 3]
O/P : [1, 2, 3, 4]

Constraints:

1) The number of nodes in the list is in the range [1, 5000].
2) -5000 <= Node.val <= 5000

Contributed By Aishwarya Karmakar
*/

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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *result = head, *curr = head->next, *tail = head, *next = nullptr;
        while(curr) {
            next = curr->next;
            if(tail && tail->val > curr->val) {
                tail->next = curr->next;
                result = insertNode(result, curr);
            } else {
                tail = curr;
            }
            curr = next;
        }
        return result;
    }
    
    ListNode* insertNode(ListNode *head, ListNode *node) {
        if(head->val >= node->val) {
            node->next = head;
            return node;
        }
        ListNode *current = head;
        while(curr->next) {
            if(curr->next->val >= node->val) {
                node->next = curr->next;
                curr->next = node;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};

//Link to problem : https://leetcode.com/problems/insertion-sort-list/ //
