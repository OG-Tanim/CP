#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> A;
    set<int> seen;

    for (int i = 1; A.size() < n; i++) {
        
        if (i == 1 || i == 2) {
            A.push_back(i);
            if (A.size() == 2) {
                seen.insert(A[0] + A[1]);
            }
            continue;
        }

        if (seen.contains(i)) continue;

        // Check if the sum of the last element and 'i' has been seen
        if (!A.empty() && seen.contains(A.back() + i)) {
            continue; 
        }

        if (!A.empty()) {
            seen.insert(A.back() + i);
        }
        A.push_back(i);
    }

    for (int x : A) cout << x << " ";
    cout << "\n";
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}