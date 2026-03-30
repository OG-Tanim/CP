#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> preSum(n);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        sum += elem;
        preSum[i] = sum;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int lhs = preSum[i];
        int rhs = ((i != 0) ? (preSum[n - 1] - preSum[i - 1]) : preSum[n -1]);
        if (lhs == rhs) count++;
    }
    cout << count;
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