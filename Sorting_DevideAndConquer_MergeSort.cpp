#include <iostream>
#include <vector>

using namespace std;

const int inf = 1e9;

void printArr(vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int p, int q, int r) {
    int n1 = q-p+1, n2 = r-q;
    vector<int> L(n1 + 1), R(n2 + 1);
    
    for (int i=0; i<n1; i++) {
        L[i] = arr[p+i];
    }
    
    for (int j=0; j<n2; j++) {
        R[j] = arr[q+1+j];
    }
    
    L[n1] = inf;
    R[n2] = inf;
    
    int i=0, j=0;
    
    printArr(arr);
    
    for (int k=p; k<r+1; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        printArr(arr);
    }
    cout << "--- p :" << p << " r : " << r << "---" << endl;
}

void mergeSort(vector<int> &arr, int p, int r) {
    if (p<r) {
        int q = (p+r)/2;
        
        mergeSort(arr, p, q);
        mergeSort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main() {
    
    vector<int> myArr = {5,4,3,2,1};
    mergeSort(myArr, 0, 4);
    printArr(myArr);

    return 0;
}