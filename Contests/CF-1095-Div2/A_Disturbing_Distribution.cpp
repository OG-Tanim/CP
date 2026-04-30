#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, mod = 676767677; cin >> n;
    vector<int> A;

    for(ll i = 0; i < n; i++) {
        ll elem;
        cin >> elem;
        A.push_back(elem);
    } 

    ll count = 0;
    if (A[n-1] == 1) count++;

    for (ll i = 0; i < n; i++) {
        if (A[i] > 1) count += A[i]; count %= mod;
    }

    cout << count << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--) {
        solve();
    } 
}
