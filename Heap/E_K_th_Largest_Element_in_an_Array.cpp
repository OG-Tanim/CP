#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<int>>; 

void solve() {
    int n, k; cin >> n >> k; 
    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    MinHeap<int> minHeap; //min heap because we have to keep the largest k values and remove the smallest of the bunch in the heap 

    for(int i = 0; i < k; i++) {
        minHeap.push(A[i]); 
    }

    //have our min heap of size K, now keep pushing and remove the smallest
    for (int i = k; i < n; i++) {
        //push first to compare the current with the all the previous k largest vals
        minHeap.push(A[i]); 

        minHeap.pop(); 
    }

    //now the min elem in the heap is the kth largest
    cout << minHeap.top(); 
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