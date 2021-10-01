#include<iostream>
using namespace std;

class queue{
    public:
    int rear;
    int front;
    int arr[5];

    queue(){
        rear=-1;
        front=-1;
        for(int i;i<=5;i++){
            arr[i] = 0;
       }
    }

    bool IsEmpty(){
        if(rear==-1 && front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool IsFull(){
        if(rear==4){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int val){
        if(IsFull()){
            cout<<"queue is full"<<endl;
            return;
        }
        else if(IsEmpty()){
            rear=0;
            front=0;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }

    int dequeue(){
        if(IsEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        else if(rear==front){
            rear=-1;
            front=-1;
        }
        else{
            arr[front]=0;
            front++;
            return 0;
        }
    }

    void display() {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 5; i++) {
      cout << arr[i] << "  ";
    }
  }

};

int main(){
    queue q1;
    int val,option;

    do{

        cout<<"enter the option"<<endl;
        cout<<"1.Check queue is full"<<endl;
        cout<<"2. Check queue is empty"<<endl;
        cout<<"3. to enqueue"<<endl;
        cout<<"4. to dequeue"<<endl;
        cout<<"5. to display the qeueue"<<endl;
        cin>>option;

        switch(option){
            case 1:
            if(q1.IsFull()){
                cout<<"queue is full"<<endl;
            }
            else{
                cout<<"queue is not full"<<endl;
            }
            break;

            case 2:
            if(q1.IsEmpty()){
                cout<<"queue is empty"<<endl;
            }
            else{
                cout<<"queue is not empty"<<endl;
            }
            break;

            case 3:
            cout<<"enter a value to enqueue"<<endl;
            cin>>val;
            q1.enqueue(val);
            break;

            case 4:
            cout<<"dequeued succesfully"<<endl;
            q1.dequeue();
            break;

            case 5:
            q1.display();
            break;

            default:
            break;

        }

    }while(option!=0);

    return 0;
}