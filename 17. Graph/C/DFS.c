// BFS algorithm using Adjacency list for undirected graph

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue
{
  int items[SIZE];
  int front;
  int rear;
};

typedef struct stack
{
  int top;
  int arr[SIZE];

} STACK;
STACK *createStack();
void push(STACK *, int);
int pop(STACK *);
void display(STACK *);
int isFull(STACK *);
int isEmpty(STACK *);

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
void dfs(struct Graph *graph, int v)
{
  STACK *s = createStack();
  push(s, v);
  while (!isEmpty(s))
  {
    v = pop(s);
    if (graph->visited[v] == 0)
    {
      graph->visited[v] = 1;
      printf("Visited %d\n", v);
      struct node *temp = graph->adjLists[v];
      while (temp != NULL)
      {
        if (graph->visited[temp->vertex] == 0)
        {
          push(s, temp->vertex);
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

void printGraph(struct Graph* graph) {
  printf("Graph is \n");
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("Vertex %d : ", v);
    while (temp!=NULL) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf(" NULL\n");
  }
}

STACK *createStack()
{
  STACK *s = malloc(sizeof(STACK));
  s->top = -1;
  return s;
}

int isFull(STACK *s)
{
  if (s->top == SIZE - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isEmpty(STACK *s)
{
  if (s->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void push(STACK *s, int ele)
{

  if (isFull(s))
  {
    printf("Stack Overflow");
  }
  else
  {
    s->arr[++(s->top)] = ele;
  }
  // printf("%d", s->top);
}

int pop(STACK *s)
{
  if (isEmpty(s))
  {
    printf("Underflow");
  }
  else
  {
    return s->arr[(s->top)--];
  }
}

void display(STACK *s)
{
  if (isEmpty(s))
  {
    printf("Empty stack");
  }
  else
  {
    printf("Stack is \n");
    for (int i = 0; i <= s->top; i++)
    {
      printf("%d ", s->arr[i]);
    }
  }
}
int main()
{

//   //User-Entered code
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
//       dfs(graph, i);
//     }
//   }

  //Hard-coded Value
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

  for (int i = 0; i < 9; i++)
  {
    if (graph->visited[i] == 0)
    {
      dfs(graph, i);
    }
  }
  return 0;
}