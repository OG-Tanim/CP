#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>A;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        A.push_back(elem);
    }

    //set initial sum
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += A[i];
    }

    int maxSum = sum;
    //left index
    int l = 0;

    //SLiding Window - shrink and expnad at the same time
    for (int r = k; r < n; r++) {
        sum += A[r];
        sum -= A[l];
        maxSum = max(sum, maxSum);
        l++;
    }

    cout << maxSum << endl; 

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}
