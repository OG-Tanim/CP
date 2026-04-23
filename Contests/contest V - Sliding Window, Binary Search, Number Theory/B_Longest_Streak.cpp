#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> A;

    for (int i = 0; i < n; i++) {
        int elem; cin >> elem;
        A.push_back(elem);
    }

    set<int> seen;
    int maxStreak = 0, l = 0;

    for (int r = 0; r < n; r++) {

        while(seen.contains(A[r])) {
            seen.erase(A[l]);
            l++;
        }

        seen.insert(A[r]);
        maxStreak = max(maxStreak, (r - l + 1));
    }

    cout << maxStreak << endl;
    
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

