#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>>A(n + 1);

    for (int i = 1; i <= n; i++) {
        //each element 
        for (int j = i; j <= n; j += i) {
            A[j].push_back(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        int s = A[i].size();

        for (int j = 0; j < s; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;

    while(t--) {
        solve();
    }
}