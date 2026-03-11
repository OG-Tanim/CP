#include <iostream>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    cout << (n * (n + 1)) / 2;
}

int main() {
    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}