/* Program for creating a minimum spanning tree from Kruskal's algorithm */
#include<stdio.h>
#define MAX 20

struct edge
{
	int u;
	int v;
	int weight;
	struct edge *link;
}*front = NULL;

int father[MAX]; /*Holds father of each node */
struct edge tree[MAX]; /* Will contain the edges of spanning tree */
int n;   /*Denotes total number of nodes in the graph */
int wt_tree=0; /*Weight of the spanning tree */
int count=0;    /* Denotes number of edges included in the tree */

/* Functions */
void make_tree();
void insert_tree(int i,int j,int wt);
void insert_pque(int i,int j,int wt);
struct edge *del_pque();

main()
{
	int i;

	create_graph();
	make_tree();
	printf("Edges to be included in spanning tree are :\n");
	for(i=1;i<=count;i++)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
	}
	printf("Weight of this minimum spanning tree is : %d\n", wt_tree);
}/*End of main()*/

create_graph()
{
	int i,wt,max_edges,origin,destin;

	printf("Enter number of nodes : ");
	scanf("%d",&n);
	max_edges=n*(n-1)/2;
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(0 0 to quit): ",i);
		scanf("%d %d",&origin,&destin);
		if( (origin==0) && (destin==0) )
			break;
		printf("Enter weight for this edge : ");
		scanf("%d",&wt);
		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			insert_pque(origin,destin,wt);
	}/*End of for*/
	if(i<n-1)
	{
		printf("Spanning tree is not possible\n");
		exit(1);
	}
}/*End of create_graph()*/

void make_tree()
{
	struct edge *tmp;
	int node1,node2,root_n1,root_n2;

	while( count < n-1) /*Loop till n-1 edges included in the tree*/
	{
		tmp=del_pque();
		node1=tmp->u;
		node2=tmp->v;

		printf("n1=%d  ",node1);
		printf("n2=%d  ",node2);

		while( node1 > 0)
		{
			root_n1=node1;
			node1=father[node1];
		}
		while( node2 >0 )
		{
			root_n2=node2;
			node2=father[node2];
		}
		printf("rootn1=%d  ",root_n1);
		printf("rootn2=%d\n",root_n2);

		if(root_n1!=root_n2)
		{
		      insert_tree(tmp->u,tmp->v,tmp->weight);
		      wt_tree=wt_tree+tmp->weight;
		      father[root_n2]=root_n1;
		}
	}/*End of while*/
}/*End of make_tree()*/

/*Inserting an edge in the tree */
void insert_tree(int i,int j,int wt)
{
	printf("This edge inserted in the spanning tree\n");
	count++;
	tree[count].u=i;
	tree[count].v=j;
	tree[count].weight=wt;
}/*End of insert_tree()*/

/*Inserting edges in the priority queue */
void insert_pque(int i,int j,int wt)
{
	struct edge *tmp,*q;

	tmp = (struct edge *)malloc(sizeof(struct edge));
	tmp->u=i;
	tmp->v=j;
	tmp->weight = wt;

	/*Queue is empty or edge to be added has weight less than first edge*/
	if( front == NULL || tmp->weight < front->weight )
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while( q->link != NULL && q->link->weight <= tmp->weight )
			q=q->link;
		tmp->link = q->link;
		q->link = tmp;
		if(q->link == NULL)	/*Edge to be added at the end*/
			tmp->link = NULL;
	}/*End of else*/
}/*End of insert_pque()*/

/*Deleting an edge from the priority queue*/
struct edge *del_pque()
{
	struct edge *tmp;
	tmp = front;
	printf("Edge processed is %d->%d  %d\n",tmp->u,tmp->v,tmp->weight);
	front = front->link;
	return tmp;
}/*End of del_pque()*/

