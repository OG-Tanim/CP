#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, target;
    cin >> n >> target;
    vector<int>A;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        A.push_back(elem);
    }
    
    //left index
    int l = 0, sum = 0, len = LLONG_MAX;

    //SLiding Window (dynamic size) : update l and r on conditions
    for (int r = 0; r < n; r++) {
        sum += A[r];

        //if window is valid: keep shrinking
        while (sum > target) {
            len = min(len, r - l + 1);
            sum -= A[l];
            l++;
        }
        //If Invalid keep on expanding : r++
    }

    cout << ((len == LLONG_MAX) ? -1 : len) << endl; 
 
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
