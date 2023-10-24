#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr){
    while(ptr!=NULL){
        cout<<"Elements :"<<ptr->data<<endl;
        ptr=ptr->next;
    }
}

struct Node* insertatnode(struct Node *head,struct Node *prevnode,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;

}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));
    head->data=44;
    head->next=second;
    second->data=22;
    second->next=third;
    third->data=33;
    third->next=fourth;
    fourth->data=11;
    fourth->next=NULL;
    cout<<"before"<<endl;
    linkedlisttraversal(head);
    cout<<"after"<<endl;
    head=insertatnode(head,second,55);
    linkedlisttraversal(head);
    return 0;
}