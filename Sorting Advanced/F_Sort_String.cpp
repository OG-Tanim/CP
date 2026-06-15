#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s; int n = s.size();
    vector<int> S(26);
    
    for (int i = 0; i < n; i++) {
        int idx = s[i] - 'a';
        S[idx]++;
    }

    for (int i = 0; i < 26; i++) {
        
        while (S[i]--) {
            char ans = 'a' + i;
            // cout << (char)('a' + i);
            cout << ans;
        }
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