#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0, maxStreak = 1;
    int l = 0, r = 0;

    while (r < n) {
        if (arr[l] == arr[r]) {
            count++;
            maxStreak = max(count, maxStreak);
            r++;
        }
        else {
            l = r;
            maxStreak = max(count, maxStreak);
            count = 0;
        }
    }

    cout << maxStreak;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}