#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

    int q, maxVal = 0; cin >> q;
    vector<int> A;

    for (int i = 0; i < q; i++) {
        int elem; cin >> elem;
        A.push_back(elem);
        maxVal = max(maxVal, elem);
    }

    vector<int> countSieve(maxVal + 1);
    //Sieve of Eratosthenes
    for (int i = 1; i <= maxVal; i++){
        for (int j = 0; j <=maxVal; j += i) {
            countSieve[j]++;
        }
    }

    for (int i = 0; i < q; i++) {
        if (countSieve[countSieve[A[i]]] == 2) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl; 
    }
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