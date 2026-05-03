#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> A(n);

    for (ll i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll bitAND = A[0], bitOR = A[0], bitXOR = A[0];
    for (ll i = 1; i < n; i++) {
        bitAND &= A[i];
        bitOR |= A[i];
        bitXOR ^= A[i];
    }

    cout << bitAND << " " << bitOR << " " << bitXOR << endl;
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