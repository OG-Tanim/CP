#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n;
    cin >> n;

    ll p2 = 1;
    
    //find biggest p2 <= n;
    while (p2 <= n) {
        p2 *= 2;
    }
    p2 /= 2;

    while (n > 0) {
        if (p2 <= n) {
            cout << p2 << " ";
            n -= p2;
        }
        p2 /= 2;
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