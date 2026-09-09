#include <bits/stdc++.h>
using namespace std;
#define int long long

template<typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>; 

void solve() {
    int n, k; cin >> n >> k; 
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    MinHeap<int> minHeap;
    //idx = 0 elem can be misplaced by k positions: so the element can be in 0th to kth index
    for (int i = 0; i <= k; i++) {
        minHeap.push(A[i]); 
    }

    int idx = 0, idx2 = k + 1; 
    while(minHeap.size() > 0) {
        //place the min elem at idx = 0 from 0 - k range, leftmost idx will be the min in the heap
        A[idx] = minHeap.top(); 
        idx++; 

        //remove the min elem
        minHeap.pop(); 

        //add the next elem after k to heap for idx = 1
        if (idx2 < n) {
            minHeap.push(A[idx2]); 
            idx2++; 
        }
    }

    //print
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