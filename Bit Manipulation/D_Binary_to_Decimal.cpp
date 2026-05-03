#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    string s;
    cin >> s;
    ll n = s.size();

    ll p2 = 1, ans = 0;

    for (ll i = n - 1; i >= 0; i--) {
        ans += ((s[i] - '0') * p2);
        p2 *= 2;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1; 
    // cin >> t;
    while(t--) {
        solve();
    }
}