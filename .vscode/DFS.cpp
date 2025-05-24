#include <iostream>
#include <list>
#include <vector>

using namespace std;

enum Color {WHITE, GRAY, BLACK};

struct Vertex {
    int id;
    Color color;
    int timeDiscover;
    int timefinish;
    Vertex *parent;
    list<int> adj;
};

class Graph {
    private:
    vector<Vertex> vertices;
    int time;
    
    public:
    Graph(int n) : time(0) {
        vertices.resize(n);

        for (int i = 0; i < n; i++) {
            vertices[i].id = i;
            vertices[i].color = WHITE;
            vertices[i].parent = nullptr;
        }
    }

    void addEdge(int u, int v) {
        /**
         * add edge (Directed Graph)
         */
        vertices[u].adj.push_back(v);
    }

    void DFS_visit(Vertex &vertex) {
        time++;
        vertex.color = GRAY;
        vertex.timeDiscover = time;

        for (int adjVertexId : vertex.adj) {
            Vertex &adjVertex = vertices[adjVertexId];

            if (adjVertex.color == WHITE) {
                adjVertex.parent = &vertex;
                DFS_visit(adjVertex);
            }
        }

        vertex.color = BLACK;
        time++;//
        vertex.timefinish = time;
    }

    void DFS() {
        for (Vertex &vertex : vertices) {
            if (vertex.color == WHITE) {
                DFS_visit(vertex);
            }
        }
    }

    void printDFS() {
        for (Vertex& u : vertices) {
            cout << "Vertex " << u.id << ": "
                 << "d = " << u.timeDiscover << ", "
                 << "f = " << u.timefinish << ", "
                 << "parent = ";
            if (u.parent) cout << u.parent->id;
            else cout << "NIL";
            cout << endl;
        }
    }

};


int main(int argc, char const *argv[])
{
     // Example graph
     Graph g(6);  // 6 vertices (0 to 5)
     g.addEdge(0, 1);
     g.addEdge(0, 2);
     g.addEdge(1, 4);
     g.addEdge(2, 4);
     g.addEdge(1, 3);
     g.addEdge(3, 5);
 
     // Run DFS
     g.DFS();
 
     // Print results
     cout << "DFS Results:" << endl;
     g.printDFS();
 
    return 0;
}
