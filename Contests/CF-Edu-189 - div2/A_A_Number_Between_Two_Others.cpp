#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int x, y;
    cin >> x >> y;

    for (int i = x + x; i < y; i += x) {
        if (y % i != 0) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    while(t--) {
        solve();
    }
}