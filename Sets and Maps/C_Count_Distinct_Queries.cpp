#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int q;
    cin >> q;
    map<int, int>map;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 3) {
            cout << map.size() << '\n';
        }
        else {
            int x;
            cin >> x;
            if (type == 1) {
                map[x] = map[x] + 1;
            }
            else if (type == 2) {
                map.erase(x);
            }
            else {
                cout << ((map.count(x) != 0) ? "YES" : "NO") << "\n";
            }
        }
    }
}

signed main() {
    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}    