#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b; cin >> a >> b;
    if (a % 2 != 0 && b % 2 != 0) {
        cout << "NO" << endl; 
    }
    else cout << "YES" << endl;
}

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t; cin >> t;
   while(t--) {
    solve();
   }
} 
