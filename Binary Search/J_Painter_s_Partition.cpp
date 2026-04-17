#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(vector<int>& A, int time, int count) {
    //traverse through the array
    int painters = 1, sum = A[0], n = A.size();

    for (int i = 1; i < n; i++) {
        if (A[i] + sum <= time) {
            sum += A[i];
        }
        else {
            sum = A[i];
            painters++;
        }
    }
    //if we need more painters than we have then the value is too small     
    return painters <= count;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //range: l = max(A), r = sum(A) 
    int l = 0, r = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] > l) l = A[i];
        r += A[i];
    }

    int ans = l;

    //Binary Search - [l, r] - find the min val: all True on the right, False on the left
    while (l <= r) {
        int m = (l + r) / 2;

        //True: search left
        if (possible(A, m, k)) {
            ans = m;
            r = m - 1;
        }
        else {
            //search right
            l = m + 1;
        }
    }

    cout << ans << endl;
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

