#include <bits/stdc++.h>
using namespace std;
#define int long long

int fn(int n) {

    if (n == 1) return 0;
    if (n == 2) return 1;

    int ans =  fn(n - 1) + fn(n - 2);

    return ans;
}


signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = fn(n);

    cout << ans << endl;
}