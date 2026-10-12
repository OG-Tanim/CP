#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int mod = 1e9 + 7; 

int fibonacchi(int n, vector<int> &dpA) {

    if (n == 0) return 0; 
    if (n == 1) return 1; 

    if (dpA[n] != -1) return dpA[n]; 

    dpA[n] = ((fibonacchi(n - 1, dpA) + fibonacchi(n - 2, dpA)) % mod); 
    
    return dpA[n]; 
}

void solve() {
    int n; cin >> n; 
    vector<int> dpA(n + 1, -1);

    int ans = fibonacchi(n, dpA); 
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