#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<vector<int>> pos(n + 2);
    for (int i = 0; i < n; ++i) {
        pos[a[i]].push_back(i);
        pos[b[i]].push_back(i);
    }
    for (int x = 1; x <= n + 1; ++x) {
        sort(pos[x].begin(), pos[x].end());
        pos[x].erase(unique(pos[x].begin(), pos[x].end()), pos[x].end());
    }

    auto next_occ = [&](int x, int i) -> int {
        if (x > n + 1 || pos[x].empty()) return -1;
        auto it = lower_bound(pos[x].begin(), pos[x].end(), i);
        if (it == pos[x].end()) return -1;
        return *it;
    };

    vector<int> dp(n + 1);
    dp[n] = n - 1;
    for (int i = n - 1; i >= 1; --i) {
        int k = a[i - 1];
        int target = k + 1;
        int j = next_occ(target, i);
        if (j == -1) {
            dp[i] = n - 1;
        } else if (a[j] == b[j]) {
            dp[i] = dp[j + 1];
        } else {
            dp[i] = j - 1;
        }
    }

    long long ans = 0;
    for (int L = 0; L < n; ++L) {
        int target = 1;
        int j = next_occ(target, L);
        int R_max = -1;
        if (j == -1) {
            R_max = n - 1;
        } else if (a[j] == b[j]) {
            R_max = dp[j + 1];
        } else {
            R_max = j - 1;
        }
        if (R_max >= L) {
            ans += (R_max - L + 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int multTestQ;
    if (cin >> multTestQ) {
        while (multTestQ--) {
            solve();
        }
    }
    return 0;
}