#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define edge pair<int, int>

class Graph {
private:
    vector<pair<int, edge>> graph;
    vector<pair<int, edge>> mst;
    int *parents;
    int size;
    
public:
    Graph(int n) {
        size = n;
        parents = new int[n];
        
        for (int i=0; i<size; i++) {
            parents[i] = i;
        }
        
        graph.clear();
        mst.clear();
    }
    
    void addEdge(int u, int v, int w) {
        graph.push_back(make_pair(w, edge(u, v)));
    }
    
    int findSet(int u) {
        if (u == parents[u]) {
            return u;
        }
        
        return findSet(parents[u]);
    }
    
    void unionSet(int u, int v) {
        parents[u] = parents[v];
    }
    
    void kruskal() {
        int u, v;
        sort(graph.begin(), graph.end());
        
        for (pair<int, edge> p : graph) {
            u = findSet(p.second.first);
            v = findSet(p.second.second);
            
            if (u != v) {
                mst.push_back(p);
                unionSet(u, v);
            }
        }
    }
    
    void printGraph() {
        for (pair<int, edge> p : mst) {
            cout << p.second.first << "-" << p.second.second << " (" << p.first << ")" << endl;
        }
        cout << endl;
    }
    
};

int main() {
    
    Graph gp(4);
    
    gp.addEdge(0, 1, 20);
    gp.addEdge(0, 2, 200);
    gp.addEdge(0, 3, 50);
    gp.addEdge(1, 2, 70);
    gp.addEdge(1, 3, 100);
    gp.addEdge(2, 3, 60);
    
    gp.kruskal();
    gp.printGraph();

    return 0;
}