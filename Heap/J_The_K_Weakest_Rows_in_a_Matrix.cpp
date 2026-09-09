#include <bits/stdc++.h>
using namespace std;
#define int long long

template<typename T>
using MaxHeap = priority_queue<T>; 

void solve() {
    int n, m, k; cin >> n >> m >> k; 
    MaxHeap<pair<int, int >> maxHeap; // { soldier count, index } - maxHeap for keep the smaller values

    for (int i = 0; i < n; i++) {

        int count = 0; 
        for (int i = 0; i < m; i++) {
            int elem; 
            cin >> elem; 

            if (elem == 1) count++; 
        }

        maxHeap.push({ count, i });

        if (maxHeap.size() > k) {
            maxHeap.pop();        //pops strongest (higer soldier count, then higher index)
        }
    }

    //now the heap holds k weakest val (max to min)
    vector<int> ans(k); 
    for (int i = k - 1; i >= 0; i--) {
        ans[i] = maxHeap.top().second; 
        maxHeap.pop(); 
    }

    for (int i = 0; i < k; i++) {
        cout << ans[i] << " "; 
    }

    cout << endl; 
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