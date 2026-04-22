using namespace std;
#include <bits/stdc++.h>
#define int long long

void solve() {
    int n; cin >> n;

    //SPF: Smallest Prime Factorial 
    vector<int> SPF;
    for (int i = 0; i <= n; i++) SPF.push_back(i);

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            SPF[j] = min(SPF[j], i);
        }
    }
    
    int count = 0;

    for (int i = 6; i <= n; i++) {

        int q = i;
        set<int>distinctPMF;

        while(q != 1) {
            int primeFactorial = SPF[q];
            distinctPMF.insert(primeFactorial);
            q /= primeFactorial;
        }
        if (distinctPMF.size() == 2) {
            count++;
        }
    }

    cout << count << endl;
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