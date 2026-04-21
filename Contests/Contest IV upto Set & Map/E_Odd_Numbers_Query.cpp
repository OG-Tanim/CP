#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> preSum(n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        sum += elem;
        preSum[i] = sum;
    }


    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        int sum = preSum[n - 1] - ((l != 0) ? preSum[r] - preSum[l - 1] : preSum[r]);
        cout << ((sum % 2 == 0) ? "NO" : "YES") << '\n';
    }
    cout << endl;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}