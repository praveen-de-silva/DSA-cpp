#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Node {
    int label;
    list<int> neighbours;
};

struct Graph
{
    int n;
    Node *nodes;

    // for DFS
    int time;
    vector<char> color;
    vector<int> parent;
    vector<int> timeDiscover;
    vector<int> timeFinish;

    Graph(int size) {
        n = size;
        nodes = new Node[n];

        for (int i = 0; i < n; i++) {
            nodes[i].label = i+1;

            // for DFS
            time = 0;
            color = vector<char> (n, 'w');
            parent = vector<int> (n, NULL);
            timeDiscover = vector<int> (n, 0);
            timeFinish = vector<int> (n, 0);
        }
    }

    ~Graph() {
        delete[] nodes;
    }
    
    void addEdge(int u, int v) {
        /*
         * add edges for directed graphs 
         */

        nodes[u-1].neighbours.push_back(v-1);
    }

    void printGraph() {
        /**
         * print the graph
         */
        for (int i=0; i<n; i++) {
            cout << nodes[i].label << " --> ";

            for (int adjVert : nodes[i].neighbours) {
                cout << adjVert+1 << " ";
            }
            cout << endl;
        }
    }

    void DFS_visit(Node &node) {
        color[node.label-1] = 'g';
        time++;
        timeDiscover[node.label-1] = time;

        for (int adjNodeVal : node.neighbours) {
            if (color[adjNodeVal] == 'w') {
                parent[adjNodeVal] = node.label;
                DFS_visit(nodes[adjNodeVal]);

            }
        }

        color[node.label-1] = 'b';
        time++;
        timeFinish[node.label-1] = time;


    }

    void DFS() {
        

        for (int i = 0; i < n; i++) {
            if (color[i] == 'w') {
                DFS_visit(nodes[i]);
            }
        }
    }
    
};

void printArr(vector<char> &arr) {
    for (char color : arr) {
        cout << color << " ";
    }
    cout << endl;
}

void printIntArr(vector<int> &arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    try {
        Graph gp = Graph(3);
        gp.addEdge(1, 2);
        printIntArr(gp.timeDiscover);
        gp.addEdge(1, 3);
        
        gp.printGraph();

        gp.DFS();
        printArr(gp.color);
        printIntArr(gp.timeDiscover);
        printIntArr(gp.timeFinish);

    } catch(...) {
        cout << "Error!" << endl;
    }

    return 0;
}
