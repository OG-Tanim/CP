#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    //find first insatnce or target elem using Binary Seatch
    for (int i = 0; i < q; i++) {

        int target;
        cin >> target;

        int l = 0, r = n - 1, ans = -1;

        while (l <= r) {

            int m = (l + r) / 2;

            if (A[m] >= target) {

                ans = m;
                //keep going with left search for a smaller valid index
                r = m - 1;
            }

            else {
                //right search whem A[m] is smalller than target
                l = m + 1; 
            }
        }

        if (ans == -1) cout << 0 << endl;
        else cout << n - ans << endl;

    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}