#include <iostream>
using namespace std;

void solve() {
    int n, q, l, r;
    cin >> n;

    long long a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    //prefix sum array
    long long sum = 0;
    long long p[n];

    for (int i = 0; i < n; i++) {
        sum += a[i];
        p[i] = sum;
    }

    //querry ranges
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        l--;
        r--;

        if (l == 0) cout << p[r];
        else cout << p[r] - p[l - 1];
        cout << endl;
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}