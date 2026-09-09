#include <bits/stdc++.h>
using namespace std;

/*
    Implement only the class below.
*/
class MaxHeap {

    vector<long long> arr; 

public:
    MaxHeap() {
        // implement
    }

    void insert(long long x) {
        // implement
        arr.push_back(x);
        int idx = size() - 1; 

        //while the newly inserted elem has parent
        while (idx > 0) {
            int parent = (idx - 1) / 2; 
            //if parent is bigger
            if (arr[parent] > arr[idx]) break;

            swap(arr[parent], arr[idx]); 
            idx = parent; 
        }
    }

    void removeMax() {
        // implement
        int n = size(); 
        if (n == 0) return; 

        //first move max to last
        swap(arr[0], arr[n - 1]);
        arr.pop_back();
        n--;  

        int idx = 0; 
        while (idx < n) {

            int lcId = 2 * idx + 1; 
            int rcId = 2 * idx + 2; 

            //left child does not exist
            if (lcId >= n) break; 
            int maxChildId = lcId; 

            //if right child exists and is greater than left child
            if(rcId < n and arr[rcId] > arr[lcId]) {
                maxChildId = rcId; 
            }

            if (arr[idx] > arr[maxChildId]) {
                break; 
            }
            
            swap(arr[idx], arr[maxChildId]); 
            idx = maxChildId; 
        } 
    }

    long long getMax() {
        // implement
        return arr.size() == 0 ? -1 : arr[0];
    }

    long long size() {
        // implement
        return arr.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MaxHeap hp;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            hp.insert(x);
        }
        else if (type == 2) {
            hp.removeMax();
        }
        else if (type == 3) {
            cout << hp.getMax() << "\n";
        }
        else {
            cout << hp.size() << "\n";
        }
    }

    return 0;
}