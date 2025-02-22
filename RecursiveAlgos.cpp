#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int getPow(int x, int n) {
    
    if (n==0) {
        return 1;
    }
    
    int half = getPow(x, n/2);
    
    if (n%2) { // if n is odd
        return x * half * half;
    } else {   // if n is even
        return half * half;
    }  
}

bool binarySearch(vector<int> &arr, int left, int right, int target) {
    if (left > right) {
        return false;
    }
    
    int mid = (right + left) / 2;
    
    if (arr[mid]==target) {
        return true;
    } else if (arr[mid] > target) {
        return binarySearch(arr, left, mid-1, target);
    } else {
        return binarySearch(arr, mid+1, right, target);
    }   
}

int main() {
    cout << getPow(3, 10);
    return 0;
}