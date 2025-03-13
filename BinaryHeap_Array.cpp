#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Heap {
    int *hArr;
    int maxSize;
    int crntSize;
    
    
    public :
        
        Heap(int aMaxSize) {
            maxSize = aMaxSize;
            crntSize = 0;
            hArr = new int[maxSize];
        }
        
        ~Heap() {
            delete[] hArr; // free alocated memory
        }
        
        // get heap node key (since it is private)
        int getKey(int i) {
            return hArr[i];
        }
        
        void insertKey(int key) {
            if (crntSize == maxSize) {
                cout << "Heap is full! cannot add " << key << endl;
                return;
            }
            
            hArr[crntSize] = key;
            crntSize++;
        }
        
        void removeKey(int key) {
            for (int i = 0; i < crntSize; i++) {
                if (hArr[i] == key) {
                    swap(hArr[i], hArr[crntSize-1]);
                    crntSize--;
                    heapify(i);
                    return;
                }
            }
            cout << "Remove fail!" << endl;
        }
        
        void printHeap() {
            for (int i=0; i < crntSize; i++) {
                cout << hArr[i] << " ";
            }
            cout << endl;
        }
        
        // heapify a node (for max-heap)
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
        void buildHeapIter() {
            for (int i = crntSize / 2 - 1; i >= 0; i--) {
                heapify(i);
            }
        }
        
        void heapSort() {
            buildHeapIter();
            int originalSize = crntSize;
            
            while (crntSize > 0) {
                swap(hArr[0], hArr[crntSize-1]);
                crntSize--; // to ignore the last node which is already sorted
                heapify(0);
            }
            
            crntSize = originalSize;
        }
        
        // Heap Increase-Key
        void increaseKey(int index, int key) {
            if (hArr[index] < key) {
                hArr[index] = key;
            }
            
            int i = index;
            while (i>0 && hArr[(i-1)/2] < hArr[i]) {
                swap(hArr[(i-1)/2], hArr[i]);
                i = (i-1)/2;
            }
        }
        
        
        
};

int main() {
    Heap mh = Heap(7);
    
    mh.insertKey(40);
    mh.insertKey(70);
    mh.insertKey(50);
    mh.insertKey(60);
    mh.insertKey(30);
    mh.insertKey(10);
    mh.insertKey(20);
    
    mh.buildHeapIter();
    mh.printHeap();
    
    mh.increaseKey(5, 55);
    cout << "\nAfter increase 30 -> 55" << endl;
    mh.printHeap();
    
    mh.removeKey(55);
    cout << "\nAfter remove 55" << endl;
    mh.printHeap();
    
    return 0;
}