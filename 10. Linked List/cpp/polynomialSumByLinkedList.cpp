#include<iostream>

class node {
    public:
    int power;
    int cofficient;
    node *next;

    node() 
    : power(0), cofficient(0), next(NULL)
    {

    }
    node(int cofficient, int power) 
    : power(power), cofficient(cofficient), next(NULL)
    {

    }
    
};

void insertEnd(node* &start, int cofficient, int power) {
    
    node* newNode = new node(cofficient, power);

    if(start==NULL){
        start=newNode;
        return;
    }

    node *tempNode=start;
    while(tempNode->next!=NULL){
        tempNode=tempNode->next;
    }

    tempNode->next=newNode;
    return;

}

void display(node *start) {
    
    if(start==NULL) {
        std::cout << "\nEmpty!\n";
    }

    // node *temp = start;
    while(start!=NULL){     //here we are using start to iterate because we have received it by value not by ref.
        if(start->next==NULL)
            std::cout << start->cofficient << "x^(" << start->power << ") ";
        else 
            std::cout << start->cofficient << "x^(" << start->power << ") + ";
        start=start->next;
    } 

    std::cout << "\n";
}

node* addPolynomial(node *head, node *head1){
    node *tempResult = new node(0,0);
    node *tempResultPointer = tempResult;

    while(head!=NULL and head1!=NULL){
        if(head->power==head1->power){
            node *tempNode= new node( head->cofficient+head1->cofficient, head->power);
            
            tempResultPointer->next=tempNode;
            head=head->next;
            head1=head1->next;
        }
        else if(head->power>head1->power){
            tempResultPointer->next=head;
            head=head->next;
        }
        else {
            tempResultPointer->next=head1;
            head1=head1->next;
        }
        tempResultPointer=tempResultPointer->next;
    }

    if(head1!=NULL){
        tempResultPointer->next=head1;
    }

    if(head!=NULL){
        tempResultPointer->next=head;
    }

    return tempResult->next;
}


int main() {
    node *head = NULL;

    insertEnd(head, 2, 2);
    insertEnd(head, 3, 1);
    
    node *head1 = NULL;

    insertEnd(head1, 5, 1);
    insertEnd(head1, 6, 0);

    std::cout << "Polynomial 1: ";
    display(head);

    std::cout << "\nPolynomial 1: ";
    display(head1);

    node *result=addPolynomial(head, head1);
    std::cout << "\nAddition of the Polynomial: ";
    display(result);

    return 0;
}