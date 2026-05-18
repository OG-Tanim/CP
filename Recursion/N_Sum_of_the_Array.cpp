#include <bits/stdc++.h>
#define int long long
using namespace std;

int sumArray (vector<int>& A, int size) {

    if (size == 0) return 0;

    int previousSum= sumArray(A, size - 1);

    int currentSum = previousSum + A[size - 1];

    return currentSum;
}

signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int ans = sumArray(A, n);

    cout << ans << endl;

}