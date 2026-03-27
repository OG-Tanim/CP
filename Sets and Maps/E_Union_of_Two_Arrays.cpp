#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    set<int>unionSet;
    int n1, n2;
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        int elem;
        cin >> elem;
        unionSet.insert(elem);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int elem;
        cin >> elem;
        unionSet.insert(elem);
    }
    cout << unionSet.size() << '\n';
    for (auto& elem : unionSet) {
        cout << elem << " ";
    } 
    cout << endl;
}

signed main() {
    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}