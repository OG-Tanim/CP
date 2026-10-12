#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int mod = 1e9 + 7; 

int tribonacchi(int n, unordered_map<int, int> &dpMap) {

    if (n == 0) return 0; 
    if (n == 1) return 1; 
    if (n == 2) return 1; 

    if (dpMap.contains(n)) return dpMap[n]; 

    int ans = (tribonacchi(n - 1, dpMap) + tribonacchi(n - 2, dpMap) + tribonacchi(n - 3, dpMap)) % mod;  
    dpMap[n] = ans; 

    if (dpMap.size() > 3)dpMap.erase(n - 4);  

    return ans; 

}

void solve() {
    int n; cin >> n; 
    unordered_map<int, int> dpMap;  
    int ans = tribonacchi(n, dpMap); 

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