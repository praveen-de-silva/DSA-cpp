#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

void bubbleSort(vector<int> arr) {
    
}


void insertionSort(vector<int> arr) {
    int temp, j;
    for (int i=1; i<arr.size(); i++) {
        temp = arr[i];
        j = i;
        
        while (j>0 && temp < arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
        }

        arr[j] = temp;
        printArr(arr);
    }
}

int main() {
    vector<int> myArr = {7,2,4,1,5,3};

    // insertionSort(myArr);

    return 0;
}
