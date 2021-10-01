#include <stdio.h>


//Max is the number of vertices
#define MAX 6

#define initial 1
#define waiting 2
#define visited 3

// diagram of graph in readme
int a[][MAX]={{0,1,1,1,0,0},{1,0,1,0,1,0},{1,1,0,0,0,0},{1,0,0,0,1,1},{0,1,0,1,0,0},{0,0,0,1,0,0}};
int queue[MAX],state[MAX],rear,front;

void printVerts(){
    for(int i=0;i<MAX;i++){
        printf("%d : %c\t\t",(i+1),(char)(i+65));
    }
}
void bfs(int v);


void insert_q(int v);

int isEmpty_queue();

int pop_queue();
void bf_traversal();
int main() {
    rear=-1;
    front=-1;
    bf_traversal();
    return 0;
}
void bf_traversal(){
    int v;
    //Setting the state of all nodes as unvisited i.e the initial state
    for(int i=0;i<MAX;i++) {
        state[i]=initial;
    }
    printf("\n");
    printVerts();
    printf("\nEnter the vertex number to start searching from");

    scanf("%d",&v);
    bfs(v-1);
}

void bfs(int v) {
    int i;
    //Insert that vertex into the queue
    insert_q(v);

    //Change the state of the vertex to waiting
    state[v]=waiting;

    while(!isEmpty_queue()){

        v=pop_queue();

        for(i=0;i<MAX;i++) {
            if (a[v][i] == 1 && state[i] == initial) {
                //i.e if an edge between the vertex and another vertex exists and the other vertex is unvisited
                //Then insert that vertex into the queue
                insert_q(i);
                state[i] = waiting;
            }
        }
        //Now that we've added all the incident vertices of the vertex, we can change it's state to visited
        state[v]=visited;
        printf("\nvisited vertex %c",(char) (v+65));
    }
}

int pop_queue() {
//    printf("\n%c",(char)(queue[front]+65));
    int temp=queue[front];
    if(front==rear){
        front=rear=-1;
    }
    else{
        front++;
    }
    return temp;
}


void insert_q(int v) {

    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=v;
    }
    else {
        rear++;
        queue[rear]=v;
    }
}
int isEmpty_queue() {
    if(front==-1 && rear==-1)
        return 1;//i.e the queue is empty
    else
        return 0;//i.e the queue isn't empty
}
