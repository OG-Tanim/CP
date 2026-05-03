    #include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n, q; cin >> n >> q;

    for (ll i = 0; i < q; i++) {
        ll type, idx; cin >> type >> idx;
        ll mask = 1LL << idx;

        switch (type)
        {
        case 1:
            cout << ((n & mask) == 0 ? "NO" : "YES") << endl;
            break;
        case 2: 
            cout << (n | mask) << endl;
            n |= mask;
            break;
        case 3:
            cout << (n & ~(mask)) << endl;
            n &= ~(mask);
            break;
        case 4: 
            cout << (n ^ mask) << endl;
            n ^= mask;
            break;
        default:
            break;
        }
    }
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