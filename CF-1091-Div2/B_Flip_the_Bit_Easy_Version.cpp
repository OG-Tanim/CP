#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, p, count = 0;
    cin >> n >> p;

    vector<int>A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> k;
    k--;

    int targetVal = A[k]; 

    int l = 0, r = n - 1;

    //leftops
    int leftOps = 0;

    for (int i = 0; i <= k; i++) {
        int udpatedVal = (A[i] + leftOps) % 2;

        if (udpatedVal != targetVal) {
            leftOps++;
        }
    }

    //rightOps
    int rightOps = 0;
    for (int i = n - 1; i >= k; i--) {
        int updatedVal = (A[i] + rightOps) % 2;

        if (updatedVal != targetVal) {
            rightOps++;
        }
    }

    int ans = max(leftOps, rightOps);

    cout << ans << endl;
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