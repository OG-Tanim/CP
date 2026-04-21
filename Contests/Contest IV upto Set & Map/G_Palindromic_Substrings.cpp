#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for(int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            bool ans = true;
            int l = i;
            int r = j;
            //[i, j]
            while (l < r) {
                if (s[l] != s[r]) {
                    ans = false;
                    break;
                } 
                else {
                    l++;
                    r--;
                }
            }
            if (ans) {
                for (int o = i; o <= j; o++) {
                    cout << s[o];
                }
                cout << endl;
            }
        }
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}