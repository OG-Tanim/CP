#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n; cin >> n;
    ll current = 1;

    while(current <= n) {
        cout << current << " ";
        current *= 2; 
    }

    cout << endl;
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
