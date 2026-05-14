#include <bits/stdc++.h>
using namespace std;
#define int long long

void fnIncreasing(int n) {

    if (n == 1) return;
    
    fnIncreasing(n - 1); 

    cout << n << '\n';
}

void fnDecreasing(int n) {

    if (n == 0) return;

    cout << n << '\n';

    fnDecreasing(n - 1);
}

void fn(int n) {

    if (n == 1) {

        cout << 1 << '\n';
        return;

    }
    
    cout << n << '\n';
    
    fn (n - 1);
    
    cout << n << '\n';
}


signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    if (n == 0) cout << 0 << endl;

    // fnDecreasing(n);
    // fnIncreasing(n);

    fn(n);

    cout << endl;
}