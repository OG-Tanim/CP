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
    int l = 0, sum = 0, len = 0;

    //SLiding Window (dynamic size) : update l and r on conditions
    for (int r = 0; r < n; r++) {
        sum += A[r];

        //if window is invalid
        //right index gets updated in each turn and l updates as long as the window is invalid
        while (sum >= target) {
            sum -= A[l];
            l++;
        }

        //if valid window
        len = max(len, r - l + 1);
    }

    cout << len << endl; 

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
