#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>; 

void solve() {
    int n, k; cin >> n >> k; 
    MaxHeap<pair<double, pair<int, int>>> distanceHeap; // { distance, co-ords }

    for (int i = 0; i < n; i++) {
        int x, y; 
        cin >> x >> y; 

        double dist = sqrt(pow((0 - x), 2) + pow((0 - y), 2)); // pow - return int(+ve) and sqrt returns double

        //push first to compare against the first k min distances
        distanceHeap.push({ dist, { x, y } });

        if (distanceHeap.size() > k) {
            distanceHeap.pop();         //maxHeap removes max distances keeping min distances  
        }
    } 

    while(distanceHeap.size() > 0) {

        cout << distanceHeap.top().second.first << " " << distanceHeap.top().second.second << '\n'; 
        
        distanceHeap.pop(); 
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