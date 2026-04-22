#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<bool> A(n + 1, true);

    for (int i = 2; i * i <= n; i++) {
        for (int j = i * i; j <= n; j += i) {
            A[j] = false; 
        }
    }
    int count = 0;
    for (int i = 2; i < n + 1; i++) {
        if (A[i]) {
            cout << i << " ";
            count++;
        }
    }

    cout << endl << count << endl;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;

    while(t--) {
        solve();
    }
} 