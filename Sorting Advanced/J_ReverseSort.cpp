#include <bits/stdc++.h>
using namespace std;
#define int long long

//Descending order: return true when a is bigger than b
bool comp(int a, int b) {
    return a > b;
}

void solve() {

    int n; cin >> n; vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //Sort Descending using cusotm comprator
    sort(A.begin(), A.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}  