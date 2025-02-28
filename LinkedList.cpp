// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    
    Node(int aData) {
        data = aData;
        next = nullptr;
    }
};

class LinkedList {
    public :
        Node *head;
        
        LinkedList(int value) {
            head = new Node(value);
        }
        
        
};

void printLL(LinkedList &lList) {
    Node *crnt = lList.head;
    
    while (crnt) {
        cout << crnt -> data << " --> ";
        crnt = crnt -> next;
    }
}

void insertNode(LinkedList &lList, int value, int index) {
    newNode = Node(value);
    
    int i = 0;
    
}

int main() {
    LinkedList myLL = LinkedList(12);
    printLL(myLL);
    return 0;
}