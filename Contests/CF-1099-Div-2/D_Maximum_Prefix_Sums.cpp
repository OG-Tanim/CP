#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18; // Safe infinity that won't overflow on basic arithmetic

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    // 1. Monotonicity check for c array
    c[0] = -INF; 
    for (int i = 1; i <= n; i++) {
        if (i > 1 && c[i] < c[i - 1]) {
            cout << "No\n";
            return;
        }
    }

    // 2. Initialize intervals [L, R] for prefix sums b
    vector<int> L(n + 1), R(n + 1);
    L[0] = 0; R[0] = 0; // b_0 is always 0

    for (int i = 1; i <= n; i++) {
        if (i == 1 || c[i] > c[i - 1]) {
            // New maximum reached, b_i must be exactly c[i]
            L[i] = c[i];
            R[i] = c[i];
        } else {
            // c[i] == c[i-1], b_i can be anything <= c[i]
            L[i] = -INF;
            R[i] = c[i];
        }
    }

    // 3. Forward propagation through fixed transitions
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            if (L[i - 1] != -INF) L[i] = max(L[i], L[i - 1] + a[i]);
            if (R[i - 1] != INF)  R[i] = min(R[i], R[i - 1] + a[i]);
        }
        if (L[i] > R[i]) {
            cout << "No\n";
            return;
        }
    }

    // 4. Backward propagation through fixed transitions
    for (int i = n; i >= 1; i--) {
        if (s[i - 1] == '1') {
            if (L[i] != -INF) L[i - 1] = max(L[i - 1], L[i] - a[i]);
            if (R[i] != INF)  R[i - 1] = min(R[i - 1], R[i] - a[i]);
        }
        if (L[i - 1] > R[i - 1]) {
            cout << "No\n";
            return;
        }
    }

    // 5. Construct the prefix sums array b
    vector<int> b(n + 1);
    b[0] = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '1') {
            b[i] = b[i - 1] + a[i];
        } else {
            // Greedy choice: stay as close to b[i-1] as bounds allow
            b[i] = max(L[i], min(R[i], b[i - 1]));
        }
        
        // Final sanity check on our constructed value
        if (b[i] < L[i] || b[i] > R[i]) {
            cout << "No\n";
            return;
        }
    }

    // 6. Output the final array a
    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << b[i] - b[i - 1] << (i == n ? "" : " ");
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}