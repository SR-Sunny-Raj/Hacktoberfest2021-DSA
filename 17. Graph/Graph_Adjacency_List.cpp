#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int x, int y, bool undir=true){
            l[x].push_back(y);
            if(undir){
                l[y].push_back(x);
            }
        }
    void printEdge(){
        for(int i=0; i<V; i++){
            cout << i << "-->";
            for(auto N : l[i]){
                cout << N << ", ";
            }
            cout << '\n';
        }
    }
};

int main(){
    Graph g(5);
    g.addEdge(0,2);
    g.addEdge(0,4);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(4,3);
    g.printEdge();
    return 0;
}