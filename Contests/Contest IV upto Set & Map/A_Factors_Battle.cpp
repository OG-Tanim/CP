#include <bits/stdc++.h>
using namespace std;
#define int long long

int countFactors(int n) {
    int limit = sqrt(n), count = 0;;
    for (int i = 1; i <= limit; i++) {
        if (n % i == 0) {
            count++;
            if (n / i != i) {
                count++;
            }
        }
    }

    return count;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int countA = countFactors(a), countB  = countFactors(b);

    if (countA > countB) cout << "A";
    else if (countB > countA) cout << "B";
    else cout << "DRAW";
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}