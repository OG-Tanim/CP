#include <iostream>
using namespace std;

void solve() {
    long long l, r;
    cin >> l >> r;
    cout << ((r * (r + 1)) / 2) - (((l - 1) * l) / 2) << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}