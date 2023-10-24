//BFS algorithm using Adjacency list for undirected graph

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue
{
  int items[SIZE];
  int front;
  int rear;
};

struct queue *createQueue();
void insertq(struct queue *q, int);
int deleteq(struct queue *q);
void display(struct queue *q);
int isEmpty(struct queue *q);
void printQueue(struct queue *q);

struct node
{
  int vertex;
  struct node *next;
};

struct node *createNode(int);

struct Graph
{
  int numVertices;
  struct node **adjLists;
  int *visited;
};

// BFS algorithm
void bfs(struct Graph *graph, int v)
{
  struct queue *q = createQueue();
  insertq(q, v);
  while (!isEmpty(q))
  {
    v = deleteq(q);
    if (graph->visited[v] == 0)
    {
      graph->visited[v] = 1;
      printf("%d visited\n", v);
      struct node *temp = graph->adjLists[v];
      while (temp != NULL)
      {
        if (graph->visited[temp->vertex] == 0)
        {
          insertq(q, temp->vertex);
        }
        temp = temp->next;
      }
    }
  }
}

struct node *createNode(int v)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph *createGraph(int vertices)
{
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node *));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++)
  {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{

  struct node *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph)
{
  printf("Graph is \n");
  int v;
  for (v = 0; v < graph->numVertices; v++)
  {
    struct node *temp = graph->adjLists[v];
    printf("Vertex %d : ", v);
    while (temp != NULL)
    {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf(" NULL\n");
  }
}

struct queue *createQueue()
{
  struct queue *q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(struct queue *q)
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void insertq(struct queue *q, int value)
{
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else
  {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

int deleteq(struct queue *q)
{
  int item;
  if (isEmpty(q))
  {
    printf("Queue is empty");
    item = -1;
  }
  else
  {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
      //   printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

void printQueue(struct queue *q)
{
  int i = q->front;

  if (isEmpty(q))
  {
    printf("Queue is empty");
  }
  else
  {
    printf("\nQueue contains \n");
    for (i = q->front; i <= q->rear; i++)
    {
      printf("%d ", q->items[i]);
    }
  }
}

int main()
{

//   // User Entered Code
//   int v, e, v1, v2;
//   printf("Enter no of Vertex\n");
//   scanf("%d", &v);
//   struct Graph *graph = createGraph(v);

//   printf("Enter no of Edges\n");
//   scanf("%d", &e);

//   for (int i = 0; i < e; i++)
//   {
//     printf("Enter the vertex that are connected \n");
//     scanf("%d", &v1);
//     scanf("%d", &v2);
//     addEdge(graph, v1, v2);
//   }

//   printGraph(graph);
//   for (int i = 0; i < v; i++)
//   {
//     if (graph->visited[i] == 0)
//     {

//       bfs(graph, i);
//     }
//   }

  //Hard-Coded
  struct Graph* graph = createGraph(9);
  addEdge(graph,0,8);
  addEdge(graph,0,3);
  addEdge(graph,0,1);
  addEdge(graph,4,8);
  addEdge(graph,3,4);
  addEdge(graph,3,2);
  addEdge(graph,1,7);
  addEdge(graph,2,7);
  addEdge(graph,2,5);
  addEdge(graph,5,6);
  printGraph(graph);

  for(int i=0;i<9;i++){
    if(graph->visited[i]==0){
      bfs(graph,i);
    }
  }

  return 0;
}