#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 1e6;

struct Edge {
    int to;
    int weight;
};

class Graph {
    int size;
    vector<vector<int>> graph;
    map<int, set<int>> adj;
    vector<int> dist;
    vector<int> parents;
    vector<bool> inMST;
    bool isMST;

    public:
    Graph(int size) {
        this->size = size;
        graph = vector<vector<int>>(size, vector<int>(size, INF));
        dist = vector<int>(size, INF);
        parents = vector<int>(size, -1);
        inMST = vector<bool>(size, false);
        isMST = false;
    }

    void addEdge(int u, int v, int w) {
        int w_min = min(w, graph[u][v]);
        graph[u][v] = w_min;
        graph[v][u] = w_min; // for undirected graphs

//        graph[u][v] = w;
//        graph[v][u] = w;

        adj[u].insert(v);
        adj[v].insert(u); // for undirected graphs
    }

    void MST_Prim(int start) {
        // most part of the initialize has done in class construction (eg : dist, parents)

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // store key and node
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {

            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (int v : adj[u]) {
                int w = graph[u][v];

                if (!inMST[v] && dist[v] > w) {
                    dist[v] = w;
                    pq.push({w, v});
                    parents[v] = u;
//                    cout << u << "-" << v << " (" << w << ")"<< endl;
                }
            }
        }
        isMST = true;
    }

    vector<int> getParents() {
        return this->parents;
    }

    vector<int> getPath(int start, int end) {
        /*
         * path in MST. (This is not SSSP)
         */
        vector<int> path;

        int crnt = end;

        do {
            path.push_back(crnt);
            crnt = parents[crnt];
        } while (crnt!=parents[start]);

        reverse(path.begin(), path.end());
        return path;
    }

    int getTotalWeight() {
        if (!isMST) MST_Prim(0);

        int totalWeight = 0;
        for (int u=0; u<size; u++) {
            if (parents[u] == -1) continue;
            int v = parents[u];

            totalWeight += graph[u][v];
        }

        return totalWeight;
    }

};

void printArr(vector<int> arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    cout << "Hello, World!" << endl;
    Graph gp(5);

//    gp.addEdge(0,1,30);
    gp.addEdge(0,1,3);
    gp.addEdge(0,1,30);
    gp.addEdge(0,2,4);
    gp.addEdge(3,1,6);
    gp.addEdge(4,1,2);
    gp.addEdge(1,2,5);
    gp.addEdge(2,4,7);

    gp.MST_Prim(0);

    printArr(gp.getParents());
    cout << "Total weight : " << gp.getTotalWeight() << endl;

    return 0;
}
