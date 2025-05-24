// Online C++ compiler to run C++ program online
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class knacsack {
    int size;
    vector<vector<int>> memory;
    int count;
    
    public:
    knacsack(int size, int capacity) {
        memory = vector<vector<int>>(size, vector<int>(capacity, -1));
        this->size = size;
        // count = 0;
    }
    
    int P(vector<int> arr_w, vector<int> arr_p, int i, int k) {
        count++;
        // cout << memory[0][0];
        int n = arr_w.size()-1;
        
        // ---- switch "Memory" ----
        if (memory[size-1-i][k-1]!=-1) {
            return memory[size-1-i][k-1];
        }
        // -------------------------
        
        int p_i;
        
        if (i==n) {
            if (arr_w[i] > k) {
                p_i = 0;
            } else {
                // memory[i][k-1] = arr_p[i];
                p_i = arr_p[i];
            }
        } else {
            if (arr_w[i] > k) {
                p_i = P(arr_w, arr_p, i+1, k);
            } else {
                p_i = max(P(arr_w, arr_p, i+1, k), arr_p[i] + P(arr_w, arr_p, i+1, k-arr_w[i]));
            }
        }
        cout << i << " " << k-1 << " " << p_i<<endl;
        memory[size-1-i][k-1] = p_i;
        return p_i;
       
    }
    
    void printMemory() {
        for (vector<int> row : memory) {
            for (int num : row) {
                cout << setw(5)<< num ;
            }
            cout << endl;
        }
    }
    
    int getCount() {
        return count;
    }
    
};


int main() {
    
    vector<int> w = { 2, 2, 6, 4, 5, 4, 5, 2, 5, 6, 3, 4};
    vector<int> p = {12,25,24,15,14,10, 5,20,12,34,12,23};
    int c = 12;
    
    knacsack ks(w.size(), c);
    
    
    cout <<  ks.P(w, p, 0, c) << " | count : " << ks.getCount() << endl;
    ks.printMemory();
    // cout << "count : " << count << endl;

    return 0;
}