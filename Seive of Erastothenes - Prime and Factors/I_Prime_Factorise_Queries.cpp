using namespace std;
#include <bits/stdc++.h>
#define int long long

void solve() {
    int maxq = 0, q; cin >> q;
    vector<int>queries;

    for (int i = 0; i < q; i++) {
        int elem; cin >> elem;
        queries.push_back(elem);
        maxq = max(elem, maxq);
    }

    //SPF: Smallest Prime Factorial 
    vector<int> SPF;
    for (int i = 0; i <= maxq; i++) SPF.push_back(i);

    for (int i = 2; i <= maxq; i++) {
        for (int j = i; j <= maxq; j += i) {
            SPF[j] = min(SPF[j], i);
        }
    }
    
    for (int i = 0; i < q; i++) {
        int n = queries[i];

        map<int, int> pmfMap;

        while(n != 1) {
            int primeFactorial = SPF[n];
            pmfMap[primeFactorial]++;
            n /= primeFactorial;
        }

        for (const auto& [key, val] : pmfMap) {
            cout << key << "^" << val << " ";
        }

        cout << '\n';
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