#include <iostream>
#include <cmath>

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

int main() {
    cout << getPow(3, 10);
    return 0;
}