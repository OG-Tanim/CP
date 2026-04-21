#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, sum = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        sum += elem;
    }

    cout << ((sum % 2 != 0 || (n * k) % 2 == 0) ? "YES" : "NO");
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}