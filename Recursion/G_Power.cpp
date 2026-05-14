#include <bits/stdc++.h>
using namespace std;
#define int long long

int fn(int x, int n) {

    if (n == 0) return 1;

    int ans = x * fn(x, n - 1);

    return ans;
}


signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n; cin >> x >> n;

    int ans = fn(x, n);

    cout << ans << endl;
}