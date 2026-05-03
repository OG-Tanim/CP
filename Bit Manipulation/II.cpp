#include <bits/stdc++.h>
using namespace std;
#define int long long

bool checkIthBit(int n, int i) {
    int mask = 1LL << i;
    if ((n & mask) == 0) return false;
    else                 return true;

} 

int setBit(int n, int i)  {
    int mask = 1LL << i;
    return (n | mask);
}

void solve() {
    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int rogue = 0;

    for (int mask = 0; mask < 64; mask++) {
        int sum = 0;

        for (int j = 0; j < n; j++) {
            if (checkIthBit(A[j], mask)) {
                sum++;
            }

        }

        if (sum % 3 != 0) {
            rogue = setBit(rogue, mask);
        }
    }

    cout << rogue << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;
    while(t--) {
        solve();
    }
}