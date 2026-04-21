#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int badPos = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) badPos++;
    }
    cout << ((badPos <= 2) ? "YES": "NO")<< endl;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    while(t--) {
        solve();
    }
}