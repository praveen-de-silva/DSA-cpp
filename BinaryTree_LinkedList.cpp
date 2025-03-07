#include <iostream>
using namespace std;

struct Node {
  int key;
  struct Node *left, *right;
  
  Node(int aKey) {
      this -> key = aKey;
      left = nullptr;
      right = nullptr;
  }
};

// Inorder traversal
void traverseInOrder(struct Node *root) {
    // unless the tree is empty 
    if (root != nullptr) {
        traverseInOrder(root -> left);
        cout << root -> key << " ";
        traverseInOrder(root -> right);
    }
    return;
}

void traversePreOrder(struct Node *root) {
    // unless the tree is empty 
    if (root != nullptr) {
        cout << root -> key << " ";
        traverseInOrder(root -> left);
        traverseInOrder(root -> right);
    }
    return;
}

void traversePostOrder(struct Node *root) {
    // unless the tree is empty 
    if (root != nullptr) {
        traverseInOrder(root -> left);
        traverseInOrder(root -> right);
        cout << root -> key << " ";
    }
    return;
}

// Insert a node
struct Node *insertNode(struct Node *root, int key) {
    struct Node *temp = root;
    struct Node *crnt = nullptr;
    
    while (temp != nullptr) {
        crnt = temp;
        
        if (temp -> key > key) {
            temp = temp -> left;
        } else {
            temp = temp -> right;
        }
    }
    
    if (crnt == nullptr) {
        return new Node(key);
    }
    
    if (crnt -> key > key) {
        crnt -> left = new Node(key);
    } else {
        crnt -> right = new Node(key);
    }
    
    return root;
}

struct Node *findMax(struct Node *node) {
    struct Node *temp = node;
    
    while (temp -> right) {
        temp = temp -> right;
    }
    
    return temp;
}

// Deleting a node
struct Node *deleteNode(struct Node *root, int key) {
    
    if (root==nullptr) {
        return root;
    } 
    
    // search in left - subtree
    if (key < root -> key) {
        root -> left = deleteNode(root -> left, key);
    } 
    // search in right - subtree
    else if (key > root -> key) {
        root -> right = deleteNode(root -> right, key);
    } 
    // found the target
    else {
        // case 01 : no child
        if (root -> left == NULL && root -> right == NULL) {
            delete root;
            root = NULL;
        } 
        // case 02 : one child
        else if (root -> left == NULL) {
            cout << root -> key << " ** ";
            struct Node *temp = root -> right;
            delete root;
            return temp;
        }
        else if (root -> right == NULL) {
            struct Node *temp = root -> left;
            delete root;
            return temp;
        }
        // Case 03 : two children
        else {
            struct Node *temp = findMax(root -> left);
            root -> key = temp -> key;
            root -> left = deleteNode(root -> left, temp -> key);
        }
    }
    return root;
}


int main() {
    struct Node *tree = NULL;
    // struct Node n1 = new Node(10);
    // struct Node n2 = new Node(30);
    tree = insertNode(tree, 20);
    tree = insertNode(tree, 10);
    tree = insertNode(tree, 30);
    // tree = insertNode(tree, 5);
    tree = insertNode(tree, 25);
    tree = insertNode(tree, 35);
    tree = insertNode(tree, 15);
    
    traverseInOrder(tree);
    cout << endl;
    
    tree = deleteNode(tree, 10);
    cout << endl;
    
    traverseInOrder(tree);
    cout << endl;
}