#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    // Case 1: Group keys are so cheap they beat buying even a single individual key
    if (b <= a) {
        int groups = (n + 2) / 3; // Equivalent to ceil(n / 3)
        cout << groups * b << "\n";
    }
    // Case 2: Individual keys are more cost-effective than a full group key
    else if (b >= 3 * a) {
        cout << n * a << "\n";
    }
    // Case 3: Group keys are best for sets of 3, but leftovers might need individual keys
    else {
        int full_groups = n / 3;
        int leftovers = n % 3;
        
        int cost = full_groups * b + min(leftovers * a, b);
        cout << cost << "\n";
    }
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}