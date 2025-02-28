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
        
        LinkedList() {
            head = nullptr;
        }
        
        LinkedList(int value) {
            head = new Node(value);
        }
        
        // insert an element
        void insertAt(int value, int index) {
            if (index < 0) {
                cout << "invalid index!" << endl;
                return;
            }
            
            Node *newNode = new Node(value);
            
            if (index==0) {
                newNode -> next = head;
                head = newNode;
                return;
            }
            
            Node *temp = head;
            
            int i = 0;
            
            while (i < index-1) {
                temp = temp -> next;
                i++;
                
                if (temp==nullptr) {
                    cout << "invalid index!" << endl;
                    delete newNode;
                    return;
                }
            }
            
            newNode -> next = temp -> next;
            temp -> next = newNode;
        }
        
        // search an element
        Node *search(int target) {
            Node *temp = head;
            
            while (temp != nullptr) {
                if ((temp -> data)==target) {
                    return temp;
                }
                
                temp = temp -> next;
            }
            return nullptr;
        }
        
        // delete an element
        void del(int value) {
            Node *temp = head;
            
            if (temp -> data == value) {
                head = temp -> next;
                temp -> next = nullptr;
            }
            
            while (temp -> next != nullptr) {
                if (temp -> next -> data == value) {
                    Node *delNode = temp -> next;
                    temp -> next = delNode -> next;
                    delete delNode;
                    cout << "Deleted!" << endl;
                    return;
                }
                
                temp = temp -> next;
            }
            cout << "Cannot delete!" << endl;
        }
        
        // insert element
        void insert(int value) {
            Node *newNode = new Node(value);
            
            // to insert en empty LL
            if (head==nullptr) {
                head = newNode;
                return;
            }
            
            Node *temp = head;
            
            // to set temp as the last node
            while (temp -> next != nullptr) {
                temp = temp -> next; 
            }
            
            temp -> next = newNode;
        }
        
};

void printLL(LinkedList &lList) {
    Node *crnt = lList.head;
    
    while (crnt) {
        cout << crnt -> data << " ";
        crnt = crnt -> next;
    }
    cout << endl;
}



int main() {
    LinkedList myLL = LinkedList();
    myLL.insert(55);
    // myLL.insertAt(20,0);
    // myLL.insertAt(44,1);
    // myLL.insertAt(14,2);
    // myLL.insertAt(40,3);
    // myLL.insertAt(30,1);
    // myLL.insert(10,7);
    printLL(myLL);
    
    cout << "------ search ------" << endl;
    Node *node = myLL.search(40);
    cout << node->data << endl;
    
    
    cout << "------ delete ------" << endl;
    myLL.del(2);
    printLL(myLL);
    
    cout << "------ insert ------" << endl;
    myLL.insert(2);
    printLL(myLL);
    return 0;
}