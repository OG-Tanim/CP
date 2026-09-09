#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>; 

void solve() {
    int n, m; cin >> n >> m; 
    vector<vector<int>> A(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j]; 
        }
    }

    MinHeap<tuple<int, int, int>> minHeap; // { val, i, j}

    //insert the first elem of each 
    for (int i = 0; i < n; i++) {
        minHeap.push({ A[i][0], i, 0 });
    }

    vector<int> ans; 
    while (minHeap.size() > 0) {

        auto [val, i, j] = minHeap.top(); 
        minHeap.pop(); 

        ans.push_back(val);
        
        //push the next elem from the same row
        int next = j + 1; 

        if (next < m) {
            minHeap.push({ A[i][next], i, next }); 
        }

    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " "; 
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