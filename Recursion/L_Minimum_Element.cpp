#include <bits/stdc++.h>
#define int long long
using namespace std;

int minElem (vector<int>& A, int size) {

    if (size == 0) return LLONG_MAX;

    int previousMin= minElem(A, size - 1);

    int currentMin = min(previousMin, A[size - 1]);

    return currentMin;
}

signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = minElem(A, n);

    cout << ans << endl;

}