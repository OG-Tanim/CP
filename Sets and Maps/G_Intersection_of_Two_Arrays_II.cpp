#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    map<int, int>mapA;
    map<int, int>mapB;
    vector<int>arrInter;
    int nA, nB;
    cin >> nA;

    for (int i = 0; i < nA; i++) {
        int elem;
        cin >> elem;
        mapA[elem]++;
    }

    cin >> nB;
    for (int i = 0; i < nB; i++) {
        int elem;
        cin >> elem;
        mapB[elem]++;
    }

    for (auto& [key, val] : mapA) {
        val = min(val, (mapB.count(key) ? mapB[key] : 0));
    }

    for (auto& [key, val] : mapA) {
        for (int i = 0; i < val; i++) {
            arrInter.push_back(key);
        }
    }

    size_t size = arrInter.size();
    cout << size << '\n';
    if (size != 0) {
        for (int i = 0; i < size; i++) {
            cout << arrInter[i] << " ";
        }
    } 
    else cout << "";
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