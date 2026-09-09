#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap  = priority_queue<T>; 

void heapifyUp(vector<int> &A, int idx) {
     
        while(idx > 0) {
            int parent = (idx - 1) / 2; 

            if (A[parent] >= A[idx]) {
                break; 
            }

            swap(A[parent], A[idx]); 
            idx = parent; 

        }
}

void heapifyDown(vector<int> &A, int idx, int size) {

    // int idx = 0;
    while (idx < size) {

        int lcIdx = 2 * idx + 1; 
        int rcIdx = 2 * idx + 2;  

        if (lcIdx >= size) {
            break; 
        }

        int maxIdx = lcIdx;

        if (rcIdx < size and A[rcIdx] > A[lcIdx]) {
            maxIdx = rcIdx;  
        }

        //max child is smaller or equal
        if (A[maxIdx] <= A[idx]) {
            break; 
        }

        swap(A[idx], A[maxIdx]); 
        idx = maxIdx; 

    }
}

void solve() {
    int n; cin >> n; 
    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    //0 to n - 1 in Place Heapify (start form idx: 1 as first elem has no parent)
    for (int i = n - 1; i >= 0; i--) {

        heapifyDown(A, i, n); 

    }

    //now move the root to last and heapify down the the sawpped val at root
    for (int i = n - 1; i >= 0; i--) {

        swap(A[0], A[i]); 

        //place A[0]: the largest at the end (last idx becomes sorted, n - 1 size remain unsorted) and leave out the already sorted part
        heapifyDown(A, 0, i); 
    }


    for (int i = 0; i < n; i++) {
        cout << A[i] << " "; 
    }
}  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}