#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct Edge {
    
    int src, dest, wgt;
    
}Edge;
 
typedef struct Graph {
    
    int V, E;
    Edge* edge;
    
}Graph;
 
Graph* createGraph(int V, int E) {
    
    Graph* graph = (Graph*)(malloc(sizeof(Graph)));
    graph->V = V;
    graph->E = E;
 
    graph->edge = (Edge*)malloc(sizeof(Edge)*E);
 
    return graph;
    
}

typedef struct Subset {
    
    int p;
    int rnk;
    
}Subset;
 
int find(Subset subsets[], int j)
{

    if (subsets[j].p != j)
        subsets[j].p = find(subsets, subsets[j].p);
 
    return subsets[j].p;
}
 
int Union(Subset subsets[], int m, int n) {   
    
    int mroot = find(subsets, m);
    int nroot = find(subsets, n);
 
    if (subsets[mroot].rnk < subsets[nroot].rnk) {
        
        subsets[mroot].p = nroot;
        return nroot;
        
    }
        
    else if (subsets[mroot].rnk > subsets[nroot].rnk) {
        
        subsets[nroot].p = mroot;
        return mroot;
        
    }
 
    else {
        
        subsets[nroot].p = mroot;
        subsets[mroot].rnk++;
        return mroot;
    }
}
 
int myComp(const void* c, const void* d)
{
    Edge* c1 = (Edge*)c;
    Edge* d1 = (Edge*)d;
    return c1->wgt > d1->wgt;
}

void KruskalMST(Graph* graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;
    int p;
 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]),
        myComp);
 
    Subset* subsets = (Subset*)malloc(V * sizeof(Subset));
    
    printf("Initialization of subsets---\n");
    printf("Parent\tRank\n");
    
    int v;
    for ( v = 0; v < V; v++) {
        
        subsets[v].p = v;
        printf("%d\t", v);
        subsets[v].rnk = 0;
        printf("0\n");
        
    }
    
    printf("Edge\tParent\tRank\n");
    
    while (e < V - 1 && i < graph->E) {

        Edge next_edge = graph->edge[i++];
        printf("%d__%d\t", next_edge.src, next_edge.dest);
        int m = find(subsets, next_edge.src);
        int n = find(subsets, next_edge.dest);
 
        if (m != n) {
            
            result[e++] = next_edge;
            p= Union(subsets, m, n);
            printf("%d\t%d\n", p, subsets[p].rnk);
            
        }
        
        else
            printf("Edge forms a cycle\n");

    }
 
    printf("\nFollowing are the edges in the constructed MST\n");
    int minimumCost = 0;
    for (i = 0; i < e; i++)
    {
        printf("%d -- %d == %d\n", result[i].src,
            result[i].dest, result[i].wgt);
        minimumCost += result[i].wgt;
    }
    printf("Minimum Cost Spanning tree : %d",minimumCost);
    return;
}
 
int main()
{
    int V, E; 
    printf("Enter vertices and edges:");
    scanf("%d %d", &V, &E);
    printf("\n");
    
    Graph* graph = createGraph(V, E);
    
    int i;
    for(i = 0; i < E; i++) {
        
        printf("Edge %d\n", i+1);
        printf("Enter source:");
        scanf("%d", &graph->edge[i].src);
        printf("Enter destination:");
        scanf("%d", &graph->edge[i].dest);
        printf("Enter weight:");
        scanf("%d", &graph->edge[i].wgt);
        
    }
 
    KruskalMST(graph);
 
    return 0;
}
