#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool checkSetBit(ll n, ll i) {
    ll mask = 1LL << i;
    return ((n & mask) != 0);
}

void solve() {
    ll n, count = 0; cin >> n;

    // for (ll i = 30; i >= 0; i--) {
    //     if (checkSetBit(n, i)) count++; 
    // }

    while (n != 0) {
        count++;
        n = (n & (n -1)); //remove the rightmost set bit 
    }

    cout << count << endl;
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