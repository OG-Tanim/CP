#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

void heapifyDown(vector<int> &A, int idx, int sz) {

    while (idx < sz) {
        
        int lcId = 2 * idx + 1; 
        int rcId = 2 * idx + 2;
        
        if (lcId >= sz) break;

        int maxId = lcId; 

        if (rcId < sz and A[rcId] > A[lcId]) {
            maxId = rcId; 
        }

        if (A[maxId] <= A[idx]) break; 

        swap(A[maxId], A[idx]); 
        idx = maxId;

    }
}

void solve() {
    int n; cin >> n; 
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    //heapify down from the bottom to minimize the number of ops to N
    for (int i = n - 1; i >= 0; i--) {

        heapifyDown(A, i, n); //array, index to be repositioned and the size
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