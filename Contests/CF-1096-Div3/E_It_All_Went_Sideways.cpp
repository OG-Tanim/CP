#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //how many are moving A[i] - min from Right;
    int minElem = LLONG_MAX, count = 0;
    map<int, int> minMap;

    for (int i = n - 1; i >= 0; i--) {
        minElem = min(minElem, A[i]);
        count += A[i] - minElem;
        minMap[minElem]++;
    }

    int maxVal = 0;
    for (const auto &[key, val]: minMap) {
        maxVal = max(maxVal, val - 1);
    }

    cout << count + maxVal << endl;
}

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t; cin >> t;
   while(t--) {
    solve();
   }
} 
