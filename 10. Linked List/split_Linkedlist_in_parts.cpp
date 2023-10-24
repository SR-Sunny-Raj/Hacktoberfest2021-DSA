//Problem link : https://leetcode.com/problems/split-linked-list-in-parts/

struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
         vector<ListNode*> a(k);
        int count=0;
        ListNode* temp=head;
        
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int x=count/k,r=count%k;
        temp=head;
        
        if(x==0 || count==k){
            for(int i=0;i<k;i++)
            {
                if(temp!=nullptr){
                a[i]=temp;
                temp=temp->next;
                    a[i]->next=nullptr;
                }
            }
            return a;
            
        }
        
        for(int i=0;i<k;i++){
            a[i]=temp;
            while(--x){
                temp=temp->next;
                
            }
            if(r!=0){
                temp=temp->next;
                r--;
            }
            if(temp!=nullptr){
            ListNode* ptr=temp->next;
            temp->next=nullptr;
            temp=ptr;
            }
        
            x=count/k;
        }
        
        return a;
        
        
    }
};
