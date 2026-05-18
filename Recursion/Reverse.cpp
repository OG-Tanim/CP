#include <bits/stdc++.h>
#define int long long
using namespace std;

void printReverse (vector<int>& A, int n) {

    if (n == 0) return;

    cout << A[n - 1] << " ";

    printReverse(A, n - 1);
}

void solve () {

    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    printReverse(A, n);

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