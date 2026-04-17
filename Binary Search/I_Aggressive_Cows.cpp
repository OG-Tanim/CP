#include <bits/stdc++.h>
using namespace std;
#define int long long

bool possible(vector<int>& A, int dist, int count) {
    //traverse throuhg the array
    int cowsPlaced = 1, prevPos = 0, n = A.size();

    for (int i = 1; i < n; i++) {
        if (A[i] - A[prevPos] >= dist) {
            prevPos = i;
            cowsPlaced++;
        }
    }
    
    return cowsPlaced >= count;
}

void solve() {
    int n, k, q = 1;
    cin >> n >> k;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < q; i++) {

        //Binary Search - find the first Index of True Instance
        int l = 0, r = A[n - 1] - A[0], ans = 0;
        
        while (l <= r) {
            int m = (l + r) / 2;
            //True - right search
            if (possible(A, m, k)) {
                ans = m;
                l = m + 1;
            }
            else {
                //False - left search
                r = m - 1;
            }
        }

        cout << ans << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}

