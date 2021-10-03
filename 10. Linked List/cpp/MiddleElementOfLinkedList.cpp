#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node){
    while(node != NULL){
        cout<<node->data<<" ";
        node = node->next;
        
    }
    cout<<"\n";
}

class Solution{
    public:
        int getMiddle(Node *head) {
            Node* slow=head;
            Node* fast=head->next;
            while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
            if(fast==NULL){
                return slow->data;
            }
            return slow->next->data;
        }
};           

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for(int i=0;i<N-1;++i){
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
          
        }
        Solution ob;
        cout<<ob.getMiddle(head)<<"\n";
          
    }
    return 0;
  

}
