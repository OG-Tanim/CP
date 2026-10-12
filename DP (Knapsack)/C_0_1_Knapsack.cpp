#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int f(int idx, int currWeight, int n, int limit, vector<int> &w, vector<int> &v, vector<vector<int>> &dpA) {

    // returns maxProfit curr idx to n - 1

    if (idx == n) {
        return 0; 
    }

    if (dpA[idx][currWeight] != -1) return dpA[idx][currWeight]; 

    // take the curr idx 
    int take = 0; 
    if (currWeight + w[idx] <= limit) {
        take = v[idx] + f(idx + 1, currWeight + w[idx], n, limit, w, v, dpA);           //we are not letting the weight of knapsack to go over limit
    }

    // don't take the curr idx
    int noTake = f(idx + 1, currWeight, n, limit, w, v, dpA); 

    return dpA[idx][currWeight] = max(take, noTake); 
}

void solve() {
    
    int n, limit; cin >> n >> limit; 
    vector<int> values(n), weights(n);  

    for (int i = 0; i < n; i++) {
        cin >> weights[i]; 
    }
    for (int i = 0; i < n; i++) {
        cin >> values[i]; 
    }

    //Solution: find all the combinatins that don't exceed the limit and return the max porfit from them

    //memoisation - states: 2 = { idx, currWeight }
    vector<vector<int>> dpA(n, vector<int> (limit + 1, -1)); 

    int ans = f(0, 0, n, limit, weights, values, dpA);               //states: idx, currWeight

    cout << ans << endl; 
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