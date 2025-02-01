#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

void insertionSort(vector<int> arr) {
    int temp;
    for (int i=1; i<arr.size(); i++) {
        temp = arr[i];
        for (int j=(i-1); j>=0; j--) {
            if (temp < arr[j]) {
                arr[j+1] = arr[j];
                printArr(arr);
            } else {
                arr[j+1] = temp;
                printArr(arr);
                break;
            }
            if (j==0) {
                arr[j] = temp;
                break;
            }
        }
        cout << "---" << endl;
    }
}

int main() {
    vector<int> myArr = {7,2,4,1,5,3};

    insertionSort(myArr);

    cout << "Try programiz.pro";

    return 0;
}
