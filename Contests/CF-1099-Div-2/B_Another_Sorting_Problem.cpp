#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; 
    cin >> n;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    int mx = 0, k = 0;
    
    for (int x : a) {
        if (x < mx) {
            k = max(k, mx - x);
        } else {
            mx = x;
        }
    }


    if (k > 0) {
        mx = 0;
        for (int &x : a) {
            if (x < mx) {
                x += k;
            }
  
            mx = max(mx, x); 
        }
    }

    // 3. Final validation check
    bool ok = true;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}