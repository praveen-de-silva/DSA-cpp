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
        
};

void heapSort(int arr[], int n) {
    // creating a heap
    Heap heap(n);
    
    // add elements to the heap
    for (int i=0; i<n; i++) {
        heap.insertKey(arr[i]);
    }
    
    // sort the heap using heap sort
    heap.heapSort();
    
    // insert the sorted values to the array
    for (int i=0; i<n; i++) {
        arr[i] = heap.getKey(i);
    }
};

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int myArr[20] = {200,190,180,170,160,150,140,130,120,110,100,90,80,70,60,50,40,30,20,10};
    heapSort(myArr, 20);
    
    printArr(myArr, 20);
    return 0;
}