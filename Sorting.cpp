#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

void bubbleSort(vector<int> &arr) {
    int temp, flag=0;
    printArr(arr);
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


void insertionSort(vector<int> &arr) {
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

void mergeSort(vector<int> &arr) {
    int mid = arr.size()/2;

    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    
    if (arr.size()>1) {
        mergeSort(left);
        mergeSort(right);
    }

    int i=0, j=0, k=0;

    while (i<left.size() && j<right.size()) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i<left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j<right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

int main() {
    vector<int> myArr = {3,2,4,1,5,7,10,6,8,9};

    // insertionSort(myArr);
    // bubbleSort(myArr);
    mergeSort(myArr); 
    printArr(myArr);

    return 0;
}
