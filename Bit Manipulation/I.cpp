#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // sort(A.begin(), A.end());
    // int l = 0, r = n - 1, ans = 0; 

    // while (l <= r) {
    //     int m = l + ((r - l) / 2);

    //     if (m != 0 && A[m] == A[m - 1]) {
    //         //pair started at m-1: if m-1 even: rogue is the on the right 

    //         if ((m - 1) % 2 == 0) {
    //             //right search
    //             l = m + 1;
    //         }
    //         else r = m - 1;
    //     }
    //     else if (m != n - 1 && A[m] == A[m + 1]) {
    //         //pair started at m: if m is even: rogue is on the right

    //         if (m % 2 == 0) {
    //             //right search
    //              l = m + ;
    //         }
    //         else {
    //             r = m - 1;
    //         }
    //     }
    //     else {
    //         ans = m;
    //         break;
    //     }
    // } 
    // cout << A[ans] << endl;

    int ans = 0;
    for (int x: A) {
        ans ^= x;
    }
    cout << ans << endl;
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