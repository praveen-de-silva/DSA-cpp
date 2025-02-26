#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// print the array
void printArr(vector<int> &arr) { 
    for (int num : arr) {
        cout << num << " ";
    }   
    cout << endl;
}

int partition(vector<int> &arr, int left, int right) {
    int i = left+1, j = right;
    int piv = arr[left];
    
    while (true) {
        while (i <= right && arr[i] < piv) i++;
        
        while (j >= left && arr[j] > piv) j--;
        
        if (i >= j) break; 
        
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    
    swap(arr[left], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        cout << left << " " << right << " | ";
        printArr(arr);
        int pivPos = partition(arr, left, right);
        
        quickSort(arr, left, pivPos-1);
        quickSort(arr, pivPos+1, right);
    }
}

int main() {
    vector<int> myArr = {10,9,8,7,6,5,4,3,2,1};
    
    quickSort(myArr, 0, myArr.size()-1);
    cout << "\nResult : \n";
    printArr(myArr);

    return 0;
}