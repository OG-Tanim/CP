#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; cin >> n;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        if (ch == '(') left++;
        else right++;
    }
    cout << (left == right ? "YES" : "NO") << endl;
}

signed main () {
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   
   int t; cin >> t;
   while(t--) {
    solve();
   }
} 

