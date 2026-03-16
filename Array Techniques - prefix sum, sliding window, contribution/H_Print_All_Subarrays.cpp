#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // [l, r]
            for (int k = i; k <= j; k++) {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}