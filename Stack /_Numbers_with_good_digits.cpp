#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n; 
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    } 
    int num; cin >> num; 

    queue<int> q; q.push(0);
    while (!q.empty()) {
        auto curr = q.front();
        q.pop(); 

        if (curr != 0) cout << curr << '\n'; 

        for (int x: A) {

            int opt = curr * 10 + x; 
            if (opt <= num) {
                q.push(opt); 
            }
        }
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