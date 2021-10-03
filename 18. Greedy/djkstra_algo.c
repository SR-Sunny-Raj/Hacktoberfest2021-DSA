#include<stdio.h>
#include<conio.h>
#define inf 99
#define max 10
void djkstra(int g[max][max], int n, int startnode);
void main()
{
int g[max][max], i, j, n, u;
printf("\nEnter the no. of vertices:: ");
scanf("%d", &n);
printf("\nEnter the adjacency matrix::\n");
for(i=0;i < n;i++)
for(j=0;j < n;j++)
scanf("%d", &g[i][j]);
printf("\nEnter the starting node:: ");
scanf("%d", &u);
djkstra(g,n,u);
getch();
}
void djkstra(int g[max][max], int n, int startnode)
{
int cost[max][max], distance[max], pred[max];
int visited[max], count, mindistance, nextnode, i,j;
for(i=0;i < n;i++)
for(j=0;j < n;j++)
if(g[i][j]==0)
cost[i][j]=inf;
else
cost[i][j]=g[i][j];
for(i=0;i< n;i++)
{
distance[i]=cost[startnode][i];
pred[i]=startnode;
visited[i]=0;
}
distance[startnode]=0;
visited[startnode]=1;
count=1;
while(count < n-1){
mindistance=inf;
for(i=0;i < n;i++)
if(distance[i] < mindistance&&!visited[i])
{
mindistance=distance[i];
nextnode=i;
}
visited[nextnode]=1;
for(i=0;i < n;i++)
if(!visited[i])
if(mindistance+cost[nextnode][i] < distance[i])
{
distance[i]=mindistance+cost[nextnode][i];
pred[i]=nextnode;
}
count++;
}
for(i=0;i < n;i++)
if(i!=startnode)
{
printf("\nDistance of %d = %d", i, distance[i]);
printf("\nPath = %d", i);
j=i;
do
{
j=pred[j];
printf(" <-%d", j);
}
while(j!=startnode);
}
}
