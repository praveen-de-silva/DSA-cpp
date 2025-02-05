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
    int temp, flag=0;
    for (int j=arr.size()-1; j>0; j--) {
        for (int i=0; i<j; i++) {
            if (arr[i]>arr[i+1]) {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                flag=1;
            }
        }

        if (flag==0) {
            break;
            return;
        }
        printArr(arr);
    }
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
    vector<int> myArr = {1,2,3,4,5};

    // insertionSort(myArr);
    bubbleSort(myArr);

    return 0;
}
