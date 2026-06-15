#include <bits/stdc++.h>
using namespace std;
#define int long long

//return true: 
//1. last digit a < last digit b;
//2. a < b
bool comp(string a, string b) {

    int sizeA = a.size();
    int sizeB = b.size();

    if (sizeA != sizeB) {
        return sizeA < sizeB;
    }

    return a < b;
}

void solve() {

    int n; cin >> n; vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //Sort Descending using cusotm comparator
    sort(A.begin(), A.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << A[i] << '\n';
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}  