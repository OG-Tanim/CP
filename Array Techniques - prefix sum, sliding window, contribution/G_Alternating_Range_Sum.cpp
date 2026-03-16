#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n, q, l, r;
    cin >> n >> q;

    //prefix - sum array: alternating one starting from positive for both even and odd
    long long p[n];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;

        if (i % 2 == 0) sum += elem;
        else sum -= elem;

        p[i] = sum;

    }

    //querry ranges 
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        l--;
        r--;

        if (l == 0)          cout << p[r];
        else if (l % 2 == 0) cout << (p[r] - p[l - 1]);         //if (l - 1) = even, means range starts from +ve like p[i]
        else                 cout << (-1 * (p[r] - p[l - 1]));  //if (l - 1) is odd, means range starts from -ve, so take opposite -p[i]
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