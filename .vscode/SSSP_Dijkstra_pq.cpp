#include <iostream>
#include <queue>
#include <vector>

using namespace std;
const int INF = 1e9;



struct Node {
    int value;
    bool visited;
    int dist;
    vector<int> neighbours;
};

class Graph {
    int size;
    Node *nodes;
    vector<vector<int>> graph;
    vector<bool> visited;

    public:
    Graph(int size) {
        this->size = size;
        nodes = new Node[size];
        graph = vector<vector<int>>(size, vector<int>(size, INF));

        for (int i=0; i<size; i++) {
            nodes[i].value = i;
            nodes[i].dist = INF;
            nodes[i].visited = false;
        }
    }

    void addEdge(int u, int v, int w) {
        graph[u][v] = w;
        nodes[u].neighbours.push_back(v);
    }

    void SSSP_Dijkstra(int start) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});
        nodes[start].dist=0;

        while (!pq.empty()) {
            int u_dist = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            // visiting if not visited yet
            if (!nodes[u].visited) {
                cout << "visited : " << u  << " | visited " << nodes[u].visited << endl;
                nodes[u].visited = true;
            }

            // relaxation
            for (int v : nodes[u].neighbours) {
                if (nodes[u].dist + graph[u][v] < nodes[v].dist && !nodes[v].visited) {
                    nodes[v].dist = nodes[u].dist + graph[u][v];
                    pq.push({nodes[v].dist, v});
                }
            }
        }

        cout << "\nFinal distances from source " << start << ":\n";
        for (int i = 0; i < size; ++i) {
            cout << "Node " << i << ": " << nodes[i].visited << endl;
        }
    }

    ~Graph() {
        delete[] nodes;
    }
};

int main() {

    cout << "Hello, World!" << endl;
    Graph gp(4);

    gp.addEdge(0, 1, 10);
    gp.addEdge(0, 2, 20);
    gp.addEdge(1, 2, 30);
    gp.addEdge(1, 3, 5);
    gp.addEdge(3, 2, 2);

    gp.SSSP_Dijkstra(0);

    return 0;
}
