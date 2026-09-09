#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>; 

void solve() {
    int n, k; cin >> n >> k; vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    unordered_map<int, int> freqMap; //{elem, freq}
    for (int i = 0; i < n; i++) {
        freqMap[A[i]]++; 
    }

    //have to store k max to min freq, for every push have to pop the min freq
    MinHeap<pair<int, int>> minHeap; 

    for (const auto& [elem, freq]: freqMap) {
        //push first to compare with the k largest till now
        minHeap.push({ freq, elem });                 //sort by freq first, so max freqs stay

        //if size of heap exceeds k
        if (minHeap.size() > k) {
            minHeap.pop(); 
        }
    }

    while(minHeap.size() > 0) {
        cout << minHeap.top().second << " "; 
        minHeap.pop(); 
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