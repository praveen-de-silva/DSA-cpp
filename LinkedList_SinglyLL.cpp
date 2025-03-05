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
        Node *tail;
        
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }
        
        LinkedList(int value) {
            head = new Node(value);
            tail = head;
        }
        
        bool isEmpty() {
            return (head == nullptr);
        }
        
        // insert an element
        void insertAt(int value, int index) {
            if (index < 0) {
                cout << "invalid index!" << endl;
                return;
            }
            
            Node *newNode = new Node(value);
            
            if (isEmpty()) {
                head = newNode;
                tail = newNode;
                return;
            }
            
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
            
            if (newNode -> next == nullptr) {
                tail = newNode;
            }
            
            cout << "-- at insert | head : " << head->data << ", tail : " << tail->data << ", tail.next : " << ((tail -> next) == nullptr) << endl; 
        }
        
        // search an element
        Node *search(int target) {
            Node *temp = head;
            
            while (temp != nullptr) {
                if ((temp -> data)==target) {
                    cout << "Found " << target << endl;
                    return temp;
                }
                
                temp = temp -> next;
            }
            cout << "Not found " << target << endl;
            return nullptr;
        }
        
        // delete an element
        void del(int value) {
            if (not(isEmpty())) {
            
                Node *temp = head; 
                
                if (temp -> data == value) {
                    head = temp -> next;
                    
                    if (head == nullptr) { // if now LL is empty
                        tail = nullptr;
                    }
                    
                    delete temp;
                    cout << "Deleted " << value << endl;
                    return;
                }
                
                while (temp -> next != nullptr) {
                    if (temp -> next -> data == value) {
                        Node *delNode = temp -> next;
                        temp -> next = delNode -> next;
                        
                        if (delNode == tail) {
                            tail = temp;
                        }
                        
                        delete delNode;
                        cout << "Deleted " << value << endl;
                        return;
                    }
                    
                    temp = temp -> next;
                }
            }
            
            cout << "Cannot delete " << value << endl;
            
        }
            
            
        
        
        // insert element
        void insert(int value) {
            Node *newNode = new Node(value);
            
            // to insert en empty LL
            if (head==nullptr) {
                head = newNode;
                tail = newNode;
                return;
            }
            
            Node *temp = head;
            
            // to set temp as the last node
            while (temp -> next != nullptr) {
                temp = temp -> next; 
            }
            
            temp -> next = newNode;
            tail = newNode;
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
    // myLL.insert(55);
    myLL.insertAt(20,0);
    myLL.insertAt(44,1);
    myLL.insertAt(14,2);
    myLL.insertAt(40,3);
    // myLL.insertAt(30,1);
    // myLL.insert(10,7);
    cout << "Print arr : ";
    
    printLL(myLL);
    cout << "current tail : " << myLL.tail -> data << endl;
    
    
    cout << "------ search ------" << endl;
    Node *node1 = myLL.search(40);
    Node *node2 = myLL.search(4);
    // cout << node->data << endl;
    
    
    cout << "------ delete ------" << endl;
    myLL.del(2);
    myLL.del(20);
    printLL(myLL);
    
    cout << "------ insert ------" << endl;
    myLL.insert(2);
    printLL(myLL);
    
    
    return 0;
}