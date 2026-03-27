#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    set<int>interSet;
    set<int>setA;
    set<int>setB;

    int n1, n2;
    cin >> n1;

    for (int i = 0; i < n1; i++) {
        int elem;
        cin >> elem;
        setA.insert(elem);
    }

    cin >> n2;
    for (int i = 0; i < n2; i++) {
        int elem;
        cin >> elem;
        setB.insert(elem);
    }

    for (auto& elem : setA) {
        if (setB.count(elem) != 0) {
            interSet.insert(elem);
        }
    }
    cout << interSet.size() << '\n';
    if (interSet.size() != 0) {
        for (auto& elem : interSet) {
            cout << elem << " ";
        }
    } 
    else cout << " ";
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