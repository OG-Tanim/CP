#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < q; i++) {
        int target; cin >> target;

        //Binary Search - find the first Index of True Instance
        int l = 0, r = n - 1, ans = -1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            //True - left search
            if (A[m] >= target) {
                ans = A[m];
                r = m - 1;
            }
            else {
                //False - right search
                l = m + 1;
            }
        }

        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}

