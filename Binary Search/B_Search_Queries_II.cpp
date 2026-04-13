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

    //Binary search
    for (int i = 0; i < q; i++) {
        int target;
        cin >> target;

        int l = 0, r = n - 1, ans = -1;

        while (l <= r) {
            //calculate mid
            int mid = (l + r) / 2;

            if (A[mid] == target) {
                ans = mid + 1;
                break;
            }

            if (A[mid] > target) {
                //right search
                l = mid + 1;
            }
            else {
                //right search
                r = mid - 1;
            }
        }

        cout << ans << endl;
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