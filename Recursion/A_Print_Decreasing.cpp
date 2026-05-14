#include <bits/stdc++.h>
using namespace std;
#define int long long

void fn(int n) {

    if (n == 0) return;

    cout << n << '\n';
    
    fn(n - 1); 
}


signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    fn(n);

}