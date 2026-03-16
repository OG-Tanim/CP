#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve() {
    int n, q, k, l, r;
    cin >> n >> q >> k;

    //sum of digits array 
    int s[n];

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        s[i] = sumOfDigits(elem);
    }

    //prefix - sum: contribution array of target statement
    int p[n];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == k) sum ++;
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