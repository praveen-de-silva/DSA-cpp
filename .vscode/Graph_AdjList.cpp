#include <iostream>
#include <list>

using namespace std;

struct Node {
    int label;
    list<int> neibhours;
};

struct Graph
{
    int n = 3;
    Node *nodes = new Node[n];

    for (int i=0; i<n; i++) {}
};
