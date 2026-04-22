using namespace std;
#include <bits/stdc++.h>
#define int long long

void solve() {
    int n; cin >> n;

    map<int, int> pmfMap;
    // int i = 2;

    //if we don't find any 2 <= factor <= sqrt{n} - the number is a prime;
    // for (int i = 2; i * i <= n; i++) { 
    //     while (n % i == 0) {
    //         pmfMap[i]++;
    //         n /= i;
    //     }
    // }

    // if (n > 1) {
    //     pmfMap[n]++;
    // }

    //SPF: Smallest Prime Factorial 
    vector<int> SPF;
    for (int i = 0; i <= n; i++) SPF.push_back(i);

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            SPF[j] = min(SPF[j], i);
        }
    }

    while(n != 1) {
        int primeFactorial = SPF[n];
        pmfMap[primeFactorial]++;
        n /= primeFactorial;
    }

    for (const auto& [key, val] : pmfMap) {
        cout << key << "^" << val << " ";
    }

    // cout << endl;
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