#include <bits/stdc++.h>
#define int long long
using namespace std;

int maxElem (vector<int>& A, int size) {

    if (size == 1) return A[size - 1];

    int previousMax= maxElem(A, size - 1);

    int currentMax = max(previousMax, A[size - 1]);

    return currentMax;
}

signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = maxElem(A, n);

    cout << ans << endl;

}