// Kruskal's algorithm in C++

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
private:
    vector<pair<int, edge> > G;  // graph
    vector<pair<int, edge> > T;  // mst
    int *parent;
    int V;  // number of vertices/nodes in graph
    
public:
    Graph(int V) {
        parent = new int[V];
        //i 0 1 2 3 4 5
        //parent[i] 0 1 2 3 4 5
        
        for (int i = 0; i < V; i++) {
            parent[i] = i;    
        }
        
        G.clear();
        T.clear();  
    }
    
    void AddWeightedEdge(int u, int v, int w) {
        G.push_back(make_pair(w, edge(u, v)));
    }
    
    int find_set(int i) {
        /*
         * by get parent can detect cycles (i.e. if 2 nodes have same parent)
         */
        
        if (i == parent[i]) {
            return i;  // if i is the parent of itself   
        }
        
        // Else if i is not the parent of itself
        // Then i is not the representative of his set,
        // so we recursively call Find on its parent
        return find_set(parent[i]);
    }
    
    void union_set(int u, int v) {
        parent[u] = parent[v];
    }
    
    void kruskal() {
        int i, uRep, vRep;
        sort(G.begin(), G.end());  // increasing weight
        
        for (i = 0; i < G.size(); i++) {
            uRep = find_set(G[i].second.first);
            vRep = find_set(G[i].second.second);
            
            if (uRep != vRep) {
                T.push_back(G[i]);  // add to tree
                union_set(uRep, vRep);
            }
        }        
    }
    
    void print() {
        cout << "Edge :" << " Weight" << endl;
        
        for (int i = 0; i < T.size(); i++) {
            cout << T[i].second.first << " - " << T[i].second.second << " : "
                 << T[i].first;
            cout << endl;
        }
    }
    
    void printParents() {
        for (int i=0; i<4; i++) {
            cout << parent[i] << " ";
        }  
        cout << "\n";
    }
};



int main() {
    Graph g(4);
  
    g.AddWeightedEdge(0, 1, 20);
    g.AddWeightedEdge(0, 2, 200);
    g.AddWeightedEdge(0, 3, 50);
    g.AddWeightedEdge(1, 2, 70);
    g.AddWeightedEdge(1, 3, 100);
    g.AddWeightedEdge(2, 3, 60);

    g.kruskal();
    g.print();
    g.printParents();
    
    return 0;
}