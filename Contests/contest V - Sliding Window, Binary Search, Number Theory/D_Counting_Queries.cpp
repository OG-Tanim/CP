#include <bits/stdc++.h>
#define int long long
using namespace std;

int lesserThan(vector<int>& A, int t, int n) {
    int idx = -1, l = 0, r = n - 1;

    while(l <= r) {
        int m = (l + r) / 2;
        if (A[m] < t) {
            l = m + 1;
            idx = m;
        }
        else r = m - 1;
    }
    return idx + 1;
}

int greaterThan(vector<int>& A, int t, int n) {
    int idx = -1, l = 0, r = n - 1;

    while(l <= r) {
        int m = (l + r) / 2;

        if (A[m] > t) {
            r = m - 1;
            idx = m;
        }
        else l = m + 1;
    }
    if (idx == -1) return 0;
    return n - idx;
}

int equals(vector<int>& A, int t, int n) {
    int idxF = -1, idxL = -1, lF = 0, rF = n - 1, lL = 0, rL = n - 1;

    //First Index
    while(lF <= rF) {
        int m = (lF + rF) / 2;

        if (A[m] == t) {
            rF = m - 1;
            idxF = m;
        }
        else if (A[m] > t) {
            rF = m - 1;
        }
        else {
            lF = m + 1;
        }
    }

    if (idxF == -1) return 0;
    //Last Index
    while(lL <= rL) {
        int m = (lL + rL) / 2;

        if (A[m] == t) {
            lL = m + 1;
            idxL = m;
        }
        else if (A[m] > t) {
            rL = m - 1;
        }
        else {
            lL = m + 1;
        }
    }

    return (idxL - idxF + 1);

}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A;

    for (int i = 0; i < n; i++) {
        int elem; cin >> elem;
        A.push_back(elem);
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < q; i++) {

        int t, x, result = 0; cin >> t >> x;

        switch (t)
        {
        case 1:
            result = equals(A, x, n);
            break;
        case 2:
            result = lesserThan(A, x, n);
            break;
        case 3:
            result = greaterThan(A, x, n);
        default:
            break;
        }

        cout << result << endl;
    }
    
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

