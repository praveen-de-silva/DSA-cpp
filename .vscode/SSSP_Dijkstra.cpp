// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

int INF = 1e6;
 
class Graph  {
    int size;
    vector<vector<int>> graph;
    
public:
    Graph(int size) {
        this->size = size;
        
        graph = vector<vector<int>>(size ,vector<int> (size, INF));
    }
    
    void addEdge(int u, int v, int w) {
        graph[u][v] = w;
        graph[v][u] = w;
    }
    
    int getMinVertex(vector<bool>& visited, vector<int>& dist) {
        int minDistIdx = -1, minDist = INF;
        
        for (int i=0; i<size; i++) {
            if (visited[i] == false && dist[i] < minDist) {
                minDistIdx = i;
                minDist = dist[i];
            }
        }
        
        return minDistIdx;
    }
    
    void SSSP_Dijkstra(int src) {
        vector<bool> visited = vector<bool>(size, false);
        vector<int> dist = vector<int>(size, INF);
        vector<int> result;
        
        dist[src] = 0;
        
        for (int count=0; count<size; ++count) {
            int u = getMinVertex(visited, dist);
            if (u == -1) {
                break;
            }
            
            visited[u] = true;
            cout << u << "  " << dist[u] << endl;
            
            for (int v=0; v<size; v++) {
                // relaxation
                if ((visited[v]==false) && (graph[u][v] != INF) && (dist[u] + graph[u][v] < dist[v])) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
};



int main() {
    Graph gp(5);
    
    gp.addEdge(0,1,5);
    gp.addEdge(0,4,15);
    gp.addEdge(1,4,6);
    gp.addEdge(4,3,2);
    
    gp.SSSP_Dijkstra(0);
    // cout << endl;

    return 0;
}