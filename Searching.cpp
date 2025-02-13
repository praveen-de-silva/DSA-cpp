#include <iostream>
#include <vector>

using namespace std;

bool binarySearch(vector<int> &arr, int target, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        
        if (arr[mid] == target) {
            cout << "Found!" << endl;
            return true;
        } else if (arr[mid] > target) {
            return binarySearch(arr, target, start, mid);
        } else {
            return binarySearch(arr, target, mid+1, end);
        }    
    }
    
    cout << "Cannot Found!";
    return false;

}

int main() {
    vector<int> myArr = {4,5,6,11,13,17,22,23,28,29};
    
    cout << binarySearch(myArr, 17, 0, 9) << endl;

    return 0;
}