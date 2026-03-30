#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    set<int>st;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        st.insert(elem);
        cout << st.size() << " ";
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