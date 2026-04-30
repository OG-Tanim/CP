#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    //All Powers of 2 have ONLY ONE set binary digit

    ll n, mask = 1, count = 0;
    cin >> n;

    while(n > 0) {
        //check if the last bit is set then right shift
        if ((n & mask) != 0) count++;
        n >>= 1;
    }

    cout << ((count == 1) ? "YES" : "NO") << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1; 
    //cin >> t;

    while(t--) {
        solve();
    }
}