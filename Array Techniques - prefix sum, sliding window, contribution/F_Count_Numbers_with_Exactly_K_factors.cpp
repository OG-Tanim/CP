#include <iostream>
#include <cmath>
using namespace std;

int numOfFactors(int n) {
    int sum = 0;
    int limit = sqrt(n);

    for (int i = 1; i <= limit; i++) {
        if (n % i == 0) {
            if (i != n/i) sum += 2;
            else sum ++;
        }
    }

    return sum;
}

void solve() {
    int n, q, k, l, r;
    cin >> n >> q >> k;

    //prefix - sum: contribution array of target statement
    int p[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        //find the number of Factors of each
        int num = numOfFactors(elem);

        //contribution array
        if (num == k) sum++;
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