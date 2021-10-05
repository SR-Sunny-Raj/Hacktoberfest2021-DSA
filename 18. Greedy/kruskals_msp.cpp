#include <iostream>
using namespace std;

#define V 6
#define INFINITY 99999

int graph[V][V] = {{0, 4, 1, 4, INFINITY, INFINITY},
                   {4, 0, 3, 8, 3, INFINITY},
                   {1, 3, 0, INFINITY, 1, INFINITY},
                   {4, 8, INFINITY, 0, 5, 7},
                   {INFINITY, 3, 1, 5, 0, INFINITY},
                   {INFINITY, INFINITY, INFINITY, 7, INFINITY, 0}};

void findMinimumEdge() {
    for (int i = 0; i < V; i++) {
        int min = INFINITY;
        int minIndex = 0;
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0 && graph[i][j] < min) {
                min = graph[i][j];
                minIndex = j;
            }
        }
        cout << i << "  -  " << minIndex << "\t" << graph[i][minIndex] << "\n";
    }
}

int main() {
    findMinimumEdge();
    return 0;
}


//1. Sort all the edges in non-decreasing order of their weight. 
//2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it. 
//3. Repeat step#2 until there are (V-1) edges in the spanning tree.
