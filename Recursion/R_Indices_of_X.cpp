#include <bits/stdc++.h>
#define int long long
using namespace std;

bool indicesX (vector<int>& A, int size, int x) {
    //base case 
    if (size == 0) return false;

    //Having faith this will print all the valid indices
    bool ans = indicesX(A, size - 1, x);

    if (!ans && A[size - 1] != x) {
        return false;
    }
    
    if (A[size - 1] == x) {
        cout << size << " ";
        return true;
    }

    else return true;
 }

signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int x; cin >> x;

    bool ans = indicesX(A, n, x);

    if (!ans) cout << -1;

}