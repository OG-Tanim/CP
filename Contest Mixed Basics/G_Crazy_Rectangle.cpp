#include <iostream>
using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    int index = 0;
    // We don't need to store the grid in an array if we are just printing it.
    // This saves O(N*M) space and prevents stack overflow.

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (index % 2 == 0) {
                // Digits 1-9: (index/2) % 9 gives 0-8, so we add 1
                cout << (char)('1' + (index / 2) % 9);
            } else {
                // Letters a-z: (index/2) % 26 gives 0-25
                cout << (char)('a' + (index / 2) % 26);
            }
            index++;
        }
        cout << '\n'; // '\n' is much faster than endl
    }
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}