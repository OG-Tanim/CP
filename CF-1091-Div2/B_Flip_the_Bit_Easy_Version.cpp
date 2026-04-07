#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, p, count = 0;
    cin >> n >> p;

    vector<int>A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cin >> k;
    k--;

    int val = A[k]; 

    int l = 0, r = n - 1;

    while (l < r) {

        while (l < k and A[l] == val) {
            l++;
        }

        while (r > k and A[r] == val) {
            r--;
        }

        if (l == r and A[l] == val ) continue;

        for (int i = l; i <= r; i++) {
                A[i] = 1 - A[i];
            }
            count++;
    }

    cout << count << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}