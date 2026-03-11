#include <iostream>
using namespace std;

void solve() {
    long long t, l, r;
    cin >> t >> l >> r;

    if (l > r) {
        cout << 0 << endl;
        return;
    }

    if (t == 1) {
        cout << ((l == r || l + 1 == r) ? 0 : (r - l - 1)) << endl;
    }
    else if (t == 2 || t == 3) {
        cout << r - l << endl;
    }
    else cout <<  r - l + 1 << endl;

}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}