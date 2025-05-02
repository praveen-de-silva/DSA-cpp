// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#define edge pair<int, int>

using namespace std;

int INF = 1e6;

class Graph {
public:
    int size;
    vector<edge> g_edges;
    vector<int> g_weights;
    vector<int> dist;
    vector<int> parents;
    
    Graph (int size) {
        this->size = size;
        
        for (int i=0; i<size; i++) {
            dist.push_back(INF);
            parents.push_back(-1);
        }
    }
    
    void addEdge(int u, int v, int w) {
        g_edges.push_back(edge(u, v));
        g_weights.push_back(w);
    }
    
    void relax(int u, int v, int w) {
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
        }
    }
    
    bool BellmanFord(int s) {
        dist[s] = 0;
        
        for (int j=0; j<size-1; j++) {
            for (int i=0; i<g_edges.size(); i++) {
                relax(g_edges[i].first, g_edges[i].second, g_weights[i]);
            }
        }
        
        for (int i=0; i<g_edges.size(); i++) {
            if (dist[g_edges[i].second] > dist[g_edges[i].first] + g_weights[i]) {
                return false;
            }
        }
        return true;
    }
};

void printArr(vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Graph gp(7);
    
    gp.addEdge(0, 1, 3);
    gp.addEdge(0, 2, 2);
    gp.addEdge(0, 3, 4);
    gp.addEdge(1, 4, 2);
    gp.addEdge(2, 3, 1);
    gp.addEdge(2, 4, 1);
    gp.addEdge(3, 4, -1);
    gp.addEdge(3, 5, 3);
    gp.addEdge(3, 6, 2);
    gp.addEdge(4, 6, 3);
    gp.addEdge(6, 5, -1);
    
    gp.BellmanFord(0);
    
    printArr(gp.dist);
    // cout << gp.dist[1];

    return 0;
}