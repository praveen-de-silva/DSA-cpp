#include <iostream>

using namespace std;

class Heap {
    int *hArr;
    int maxSize;
    int crntSize = 0;
    
    public :
        
        Heap(int aMaxSize) {
            maxSize = aMaxSize;
            hArr = new int[maxSize];
        }
        
        ~Heap() {
            delete[] hArr; // free alocated memory
        }
        
        void insertKey(int key) {
            if (crntSize == maxSize) {
                cout << "Heap is full! cannot add " << key << endl;
                return;
            }
            
            hArr[crntSize] = key;
            crntSize++;
        }
        
        void printHeap() {
            for (int i=0; i < crntSize; i++) {
                cout << hArr[i] << " ";
            }
        }
        
        // heapify a node
        void heapify(int k) {
            int l = 2 * k + 1;
            int r = 2 * k + 2;
            int largest = k;
            
            if (l < crntSize && hArr[l] > hArr[largest]) {
                largest = l;
            } 
            
            if (r < crntSize && hArr[r] > hArr[largest]) {
                largest = r;
            }
            
            if (largest != k) {
                swap(hArr[largest], hArr[k]);
                heapify(largest);
            }
        }
        
        // build heap
        void build
};

int main() {
    Heap mh = Heap(7);
    mh.insertKey(10);
    mh.insertKey(20);
    mh.insertKey(15);
    mh.insertKey(5);
    mh.insertKey(30);
    mh.insertKey(45);
    mh.insertKey(25);
    
    cout << "Before Heapify" << endl;
    mh.printHeap();
    cout << endl;
    
    mh.heapify(2);
    
    cout << "After Heapify" << endl;
    mh.printHeap();
    cout << endl;

    return 0;
}