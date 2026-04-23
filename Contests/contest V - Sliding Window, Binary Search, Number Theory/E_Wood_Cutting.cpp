#include <bits/stdc++.h>
#define int long long
using namespace std;
bool possible(vector<int>& A, int n, int m, int k) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += A[i] / m;
    }
    return count >= k; 
}
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A;
    
    int sum = 0, maxElem = 0;
    for (int i = 0; i < n; i++) {
        int elem; cin >> elem;
        A.push_back(elem);

        sum += elem;
        maxElem = max(maxElem, elem);
    }

    if (sum < k) {
        cout << 0 << endl;
        return;
    }

    sort(A.begin(), A.end());

    int l = 1, r = maxElem, ans = 1;

    while(l <= r) {
        int m = (l + r) / 2;

        if (possible(A, n, m, k)) {
            //right search
            l = m + 1;
            ans = m;
        }
        else {
            //left search 
            r = m - 1;
        }
    }

    cout << ans << endl;
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

