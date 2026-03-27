#include <bits/stdc++.h>
#include <map>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, int>indexMap;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        indexMap[elem] = i + 1;
    }

    for (int i = 0; i < q; i++) {
        int elem;
        cin >> elem;
        cout << ((indexMap.contains(elem)) ? indexMap[elem] : -1) << '\n';
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}   