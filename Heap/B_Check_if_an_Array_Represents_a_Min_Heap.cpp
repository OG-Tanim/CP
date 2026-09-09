#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n; 
    vector<int> a(n); 
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    bool ans = true; 

    for (int i = 0; i < n; i++) {

        int lcIdx = 2 * i + 1; 
        int rcIdx = 2 * i + 2; 

        if ((lcIdx < n and a[lcIdx] < a[i]) or (rcIdx < n and a[rcIdx] < a[i])) {
            ans = false; 
            break; 
        }

        // if (rcIdx < n and a[rcIdx] < a[i]) {
        //     ans = false; 
        //     break; 
        // }

        if (lcIdx >= n or rcIdx >= n) break; 
    }

    cout << (ans ? "YES" : "NO") << endl;  
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