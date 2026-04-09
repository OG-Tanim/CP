#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string S;
    cin >> S;
     
    //left index
    int l = 0, len = 0;
    set<int>distinctNums;

    //SLiding Window (dynamic size) : update l and r on conditions
    for (int r = 0; r < n; r++) {

        //if window is invalid
        //right index gets updated in each turn and l updates as long as the window is invalid
        while (distinctNums.contains(S[r])) {
            distinctNums.erase(S[l]);
            l++;
        }

        //if valid window
        distinctNums.insert(S[r]);
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
