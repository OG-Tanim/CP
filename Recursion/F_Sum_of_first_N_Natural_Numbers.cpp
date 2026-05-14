#include <bits/stdc++.h>
using namespace std;
#define int long long

int fn(int n) {

    if (n == 0) return 0;

    int ans =  n + fn(n - 1);

    return ans;
}


signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    int ans = fn(n);

    cout << ans << endl;
}