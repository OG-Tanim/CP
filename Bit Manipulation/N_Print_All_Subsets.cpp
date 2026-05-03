#include <bits/stdc++.h>
using namespace std;
#define int long long

bool checkIthBit(int n, int i) {
    int mask = 1LL << i;
    if ((n & mask) == 0) return 0;
    else                 return 1;

} 

void solve() {
    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int limit = 1LL << n;

    for (int i = 1; i < limit; i++) {

        for (int mask = 0; mask < n; mask++) {

            if (checkIthBit(i, mask) == 1) {
                cout << A[mask] << " ";
            }
        }

        cout << endl;
    }

    cout << endl;
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