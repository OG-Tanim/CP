#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int q; cin >> q;
    vector<int> A;
    int maxVal = 0;
    for (int i = 0; i < q; i++) {
        int elem;
        cin >> elem;
        maxVal = max(maxVal, elem);
        A.push_back(elem);
    }
    vector<bool> PrimeNumbers(maxVal + 1, true);
    PrimeNumbers[0], PrimeNumbers[1] = false;

    for (int i = 2; i * i <= maxVal; i++) {
        for (int j = i * i; j <= maxVal; j += i) {
            PrimeNumbers[j] = false; 
        }
    }

    for (int i = 0; i < q; i++) {
        if (PrimeNumbers[A[i]]) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
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