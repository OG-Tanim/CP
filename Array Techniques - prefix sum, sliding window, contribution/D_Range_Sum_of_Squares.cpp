#include <iostream>
using namespace std;

void solve() {
    int n, q, l, r;
    cin >> n >> q;

    //prefix sum array 
    long long sum = 0;
    long long p[n];

    for (int i = 0; i < n; i++) {
        long long elem;
        cin >> elem;
        sum += (elem * elem);
        p[i] = sum;
    }

    //querry ranges
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