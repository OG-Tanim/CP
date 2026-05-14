#include <bits/stdc++.h>
using namespace std;
#define int long long

void fn(int n) {

    if (n == 0) return;
    
    fn(n - 1); 

    cout << n << '\n';
}


signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if (n == 0) cout << 0 << endl;

    fn(n);

    cout << endl;
}