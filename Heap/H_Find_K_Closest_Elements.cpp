#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>; 

void solve() {
    int n, k, x; cin >> n >> k >> x; 

    //max pops, min stays
    MaxHeap<pair<int, int>> distanceHeap; // { distance, elem }

    for (int i = 0; i < n; i++) {
        int elem; 
        cin >> elem; 

        int dist = abs(x - elem);  

        //push first to compare against the first k min distances
        distanceHeap.push({ dist, elem });

        if (distanceHeap.size() > k) {
            distanceHeap.pop();         //maxHeap removes max distances keeping min distances  
        }
    } 

    vector<int> ans; 

    while(distanceHeap.size() > 0) {

        ans.push_back(distanceHeap.top().second); 
        
        distanceHeap.pop(); 
    }

    sort(ans.begin(), ans.end()); 
    for (int x: ans) {
        cout << x << " "; 
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