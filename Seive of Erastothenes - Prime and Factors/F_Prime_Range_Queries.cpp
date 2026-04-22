#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q; cin >> n >> q;

    vector<bool>isPrime(n + 1, true); vector<int>preSum(n + 1);
    //Prime Sieve
    isPrime[0], isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        for (int j = i * i; j <=n; j += i) {
            isPrime[j] = false;
        }
    }

    //Prime Number Count Prefix Sum
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            sum++;
            preSum[i] = sum;
        }
        else preSum[i] = sum;
    }
    
    //Output for the ranges
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        cout << ((r > 2) ? preSum[r] - preSum[l - 1] : preSum[r]) << '\n';
    }

    cout << endl;
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;

    while(t--) {
        solve();
    }
} 