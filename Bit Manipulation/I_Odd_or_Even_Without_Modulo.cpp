    #include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n; cin >> n;

    if ((n & 1) == 0) cout << "Even" << endl;
    else cout << "Odd" << endl;
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