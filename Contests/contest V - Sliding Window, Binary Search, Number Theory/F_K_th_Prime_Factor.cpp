#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int q; cin >> q;

    //SPF array
    int size = 1e6;
    vector<int>SPF;

    for (int i = 0; i <= size; i++) {
        SPF.push_back(i);
    }

    for (int i = 2; i * i <= size; i++) {

        if (SPF[i] == i) {

            for (int j = i * i; j <= size; j += i) {
               SPF[j] = min(SPF[j], i);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int n, k; cin >> n >> k;
        int nn = n;

        vector<int>primeFactorials;

        while (n != 1) {
            primeFactorials.push_back(SPF[n]);
            n /= SPF[n];
        }

        if (primeFactorials.size() < k || nn < 2) {
            cout << -1 << endl;
        }

        else cout << primeFactorials[k - 1] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}

