#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string S; cin >> S;
    int depth = 0;
    int count = 0;

    for (char ch: S) {

        if (ch == '(') {
            count++; 
        }

        if (ch == ')') {
            count--;
        }

        depth = max(depth, count);
    }

    cout << depth << endl; 
}  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}