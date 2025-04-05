// Online C++ compiler to run C++ program online
#include <iostream>
#include <cstring>

using namespace std;

// ==== Node ====
struct Node {
    const char* key;
    const char* value;
    struct Node* next;
};

void setNode(struct Node* node, const char* key, const char* value) {
    /*
    * set new node
    */
    node -> key = key;
    node -> value = value;
    node -> next = nullptr;
    return;
}

// ==== HashMap ====
struct HashMap {
    int numOfElements, capacity;
    struct Node** arr;
};

void initHashMap(struct HashMap* mp) {
    /*
    * set new HashMap
    */
    mp -> capacity = 100;
    mp -> numOfElements = 0;
    mp -> arr = (struct Node**)malloc(sizeof(struct Node*) * mp -> capacity);
    return;
}

// ---- methods() ----
int hashFunc(struct HashMap* mp, const char* key) {
    /*
    * calculate hash code
    */
    int bucketIndex;
    int sum = 0, factor = 31;
    
    for (int i = 0; i<strlen(key); i++) {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    
    bucketIndex = sum;
    return bucketIndex;
}

void insert(struct HashMap* mp, const char* key, const char* value) {
    /*
    * insert values to hash map
    */
    int bucketIndex = hashFunc(mp, key);
    cout << bucketIndex << endl;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    setNode(newNode, key, value);
    
    if (mp->arr[bucketIndex] == nullptr) {
        mp->arr[bucketIndex] = newNode;
    } else {
        struct Node* temp = mp->arr[bucketIndex];
        
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        
        temp->next = newNode;
    }
}

void deleteKey(struct HashMap* mp, const char* keyTarget) {
    /*
    * remove a node from hash map
    */
    int bucketIndex = hashFunc(mp, keyTarget);
    struct Node* prevNode = mp->arr[bucketIndex];
    struct Node* crntNode = mp->arr[bucketIndex];
    
    while (crntNode != nullptr) {
        if (crntNode->key == keyTarget) {
            if (crntNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = crntNode->next;
            } else {
                prevNode->next = crntNode->next;
            }
            free(crntNode);
            break;
        }

        prevNode = crntNode;
        crntNode = crntNode->next;
    }
    return;
}




int main() {
    // Write C++ code here
    struct Node* n1;
    struct Node* n2;
    
    
    
    n1 = (struct Node*)malloc(sizeof(struct Node));
    setNode(n1, "Praveen", "Sandami");
    
    struct HashMap* mp = (struct HashMap*)malloc(sizeof(struct HashMap));
    initHashMap(mp);
    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    
    cout << mp->arr[76]->key << endl;
    
    deleteKey(mp, "Yogaholic");
    
    cout << mp->arr[61]->key << endl;

    return 0;
}