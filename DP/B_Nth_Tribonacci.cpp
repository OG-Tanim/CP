#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int mod = 1e9 + 7; 

int tribonacchi(int n, vector<int> &dpA) {

    if (n == 0) return 0; 
    if (n == 1) return 1; 
    if (n == 2) return 1; 

    if (dpA[n] != -1) return dpA[n]; 

    int ans = (tribonacchi(n - 1, dpA) + tribonacchi(n - 2, dpA) + tribonacchi(n - 3, dpA)) % mod;  
    dpA[n] = ans; 

    return ans; 
}

void solve() {
    int n; cin >> n; 
    vector<int> dpA(n + 1, -1); 
    int ans = tribonacchi(n, dpA); 

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