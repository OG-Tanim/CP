#include <bits/stdc++.h>
using namespace std;
#define int long long

//return true: 
//1. last digit a < last digit b;
//2. a < b
bool comp(int a, int b) {

    int absA = abs(a);
    int absB = abs(b);

    if (absA != absB) {
        return absA < absB;
    }

    return a < b;
}

void solve() {

    int n; cin >> n; vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //Sort Descending using cusotm comparator
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