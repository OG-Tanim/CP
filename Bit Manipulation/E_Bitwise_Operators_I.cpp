#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll A, B;
    cin >> A >> B;

    cout << (A & B) << " " << (A | B) << " " << (A ^ B) << endl;
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