#include <iostream>
#include <sstream>
#include <vector>

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
        void buildHeapIter() {
            for (int i = crntSize / 2 - 1; i >= 0; i--) {
                heapify(i);
            }
        }
};

class HeapSort {
    
};

int main() {
    string userInp;
    vector<int> nums;
    
    cout << "Enter space sep integers : ";
    getline(cin, userInp);
    
    stringstream ss(userInp);
    int num;
    
    // split user input and add them to 'nums'
    while (ss >> num) {
        nums.push_back(num);
    }
    
    int countNums = nums.size(); // numbers count = heap size
    Heap heap = Heap(countNums); // creating heap
    
    // add numbers to heap
    for (int i=0; i < countNums; i++) {
        heap.insertKey(nums[i]);    
    }
    
    // before build Heap
    cout << "Before Heapify" << endl;
    heap.printHeap();
    cout << endl;
    
    heap.buildHeapIter();
    
    // after build Heap
    cout << "After Heapify" << endl;
    heap.printHeap();
    cout << endl;

    return 0;
}