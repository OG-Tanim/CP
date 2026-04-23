#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> A;

    for (int i = 0; i < n; i++) {
        int elem; cin >> elem;
        A.push_back(elem);
    }

    int sum = 0, count = 0;
    for (int i = 0; i < k; i++) {
        sum += A[i];
    }

    if ((sum / k) >= t) count++;

    int l = 0;
    for (int r = k; r < n; r++) {
        sum += A[r];
        sum -= A[l];

        if ((sum / k) >= t) count++;
        l++;
    }

    cout << count << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}

