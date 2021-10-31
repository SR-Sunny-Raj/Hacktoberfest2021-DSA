#include<iostream>
#include<list>
#include<string>
#include<vector>
#include<unordered_map>

class node{
public:
    std::string name;
    std::list<std::string> nbrs;
    node(std::string x){
        this->name = x;
    }
};

class Graph{
    std::unordered_map<std::string, node*> m;
       
public:
    Graph(std::vector<std::string> cities){
        for(auto i : cities){
            m[i] = new node(i);
        }
    }        
    void addEdge(std::string x, std::string y, bool undir=false){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }
    void printAdjList(){
        for(auto cityPair : m){
            auto city = cityPair.first;
            node *n = cityPair.second;
            std::cout << city << "-->";
            for(auto nbr : n->nbrs){
                std::cout << nbr << ", ";
            }
            std::cout << std::endl;
        }
    }
};   

int main(){
    std::vector<std::string> cities = {"Delhi", "Mumbai", "Kolkata", "Chitrakoot"};
    Graph g(cities);

    g.addEdge("Delhi","Chitrakoot");
    g.addEdge("Chitrakoot", "Delhi");
    g.addEdge("Mumbai", "Delhi");
    g.addEdge("Mumbai", "Kolkata");
    g.addEdge("Kolkata", "Chitrakoot");
    g.addEdge("Delhi","Kolkata");

    g.printAdjList();
    return 0;
}