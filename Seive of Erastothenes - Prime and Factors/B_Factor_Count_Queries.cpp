#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int q, maxElem = 0; cin >> q;
    vector<int> A;

    for (int i = 0; i < q; i++) {
        int elem; cin >> elem;
        maxElem = max(maxElem, elem);
        A.push_back(elem);
    }

    vector<int> factorCount(maxElem + 1);

    for (int i = 1; i <= maxElem; i++) {
        for (int j = i; j <= maxElem; j += i) {
            factorCount[j]++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << factorCount[A[i]] << '\n';
    }

    cout << endl;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;

    while(t--) {
        solve();
    }
} 