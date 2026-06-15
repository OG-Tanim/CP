#include <bits/stdc++.h>
using namespace std;
#define int long long


bool comp(int a, int b) {

    //concate the two options
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
 
    // if (ab > ba) return true;
    // else return false;

    return ab > ba;
}

void solve() {

    int n; cin >> n; vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //Sort Descending using cusotm comparator
    sort(A.begin(), A.end(), comp);

    if (A[0] == 0) {
        cout << 0 << endl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        cout << A[i];
    }

    cout << endl;
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