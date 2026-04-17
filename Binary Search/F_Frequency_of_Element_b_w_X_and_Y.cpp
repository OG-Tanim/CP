#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < q; i++) {

        int x, y; cin >> x >> y;
        if (x > y) {
            cout << 0 << endl;
            continue;
        }

        //Binary Search for left end: x - find the first Index of True Instance: elem >= x
        int l1 = 0, r1 = n - 1, leftIndex = -1;
        
        while (l1 <= r1) {
            int m = (l1 + r1) / 2;
            //True - left search
            if (A[m] >= x) {
                leftIndex = m;
                r1 = m - 1;
            }
            else {
                //False - right search
                l1 = m + 1;
            }
        }

        if (leftIndex == -1) {
            cout << 0 << endl;
            continue;
        }

        //Binary Search for right end: y - find the last Index of True Instance: elem <= y
        int l2 = 0, r2 = n - 1, rightIndex = -1;
        
        while (l2 <= r2) {
            int m = (l2 + r2) / 2;
            //True - right search
            if (A[m] <= y) {
                rightIndex = m;
                l2 = m + 1;
            }
            else {
                //False - left search
                r2 = m - 1;
            }
        }

        cout <<  rightIndex - leftIndex + 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}

