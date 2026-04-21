#include <bits/stdc++.h>
using namespace std;
#define int long long

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vector<int> A(n);
//     for (int i = 0; i < n; i++) {
//         cin >> A[i];
//     }

//     int p = -1, s = 0;
//     int limit = 3 * n + 5;

//     while(p < n - 1) {
//         //iterate seconds
//         s++;
//         if (s > limit) {
//             cout << "NO" << endl;
//             return;
//         }
//         //right move
//         if ((A[p + 1] + s) % m != 0) {
//             p++;
//         }
//         //stay in position
//         else if ((p == -1 && (A[p + 1] + s) % m == 0) || ((A[p] + s) % m != 0)) {
//             continue;
//         }
//         //left move 
//         else if (p > 0 && ((A[p - 1] + s) % m != 0)) {
//             p--;
//         }
//         //left, right, current position all invalid 
//         else {
//             cout << "NO" << endl;
//             return;
//         }
//      }
//      cout << "YES" << endl;    
// }

// THe above works but not Good Enough (TLE)
// The Solution depends on the the relation between consecutive elements of same value and "m" - if there is a block >= m - Hector can't escape 

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int count = 0, maxCount = 0;

    for (int i = 0; i < n - 1; i++) {

        if (A[i] == A[i+1]) {
            count++;
        }

        else {
            maxCount = max(maxCount, count + 1);
            if (maxCount >= m) {
                cout << "NO" << endl;
                return;
            }
            count = 0;
        }
    }
    
    if (count + 1 >= m) cout << "NO" << endl;
    else cout << "YES" << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}