#include <iostream>
#include <list>
#include <queue>

using namespace std;

struct Node {
    int label;
    list<int> neibhours;
};

struct Graph
{
    int n;
    Node *nodes;

    Graph(int size) {
        n = size;
        nodes = new Node[n];

        for (int i = 0; i < n; i++) {
            nodes[i].label = i+1;
        }
    }

    ~Graph() {
        delete[] nodes;
    }
    
    void addEdge(int u, int v) {
        /*
         * add edges for undirected graphs 
         */
        nodes[u-1].neibhours.push_back(v-1);
        nodes[v-1].neibhours.push_back(u-1);
    }

    void printGraph() {
        /**
         * print the graph
         */
        for (int i=0; i<n; i++) {
            cout << nodes[i].label+1 << " --> ";

            for (int adjVert : nodes[i].neibhours) {
                cout << adjVert+1 << " ";
            }
            cout << endl;
        }
    }

    void BFS(int start) {
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(start-1);
        visited[start-1] = true;

        while (!q.empty()) {
            int crnt = q.front();
            cout << crnt + 1 << " ";
            q.pop(); // dequeue

            // add neigbhours of crnt
            for (int neigbhour : nodes[crnt].neibhours) {
                // enqueuing only unless visited
                if (!visited[neigbhour]) {
                    q.push(neigbhour);
                    visited[neigbhour] = true;
                }
            }

            
        }
    }
};

int main() {
    Graph gp = Graph(5);
    gp.addEdge(1, 2);
    gp.addEdge(2, 3);
    gp.addEdge(1, 3);
    gp.addEdge(3, 4);
    gp.addEdge(4, 5);


    // gp.printGraph();
    gp.BFS(1);

    return 0;
}
