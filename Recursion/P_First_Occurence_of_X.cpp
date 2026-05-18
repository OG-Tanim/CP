#include <bits/stdc++.h>
#define int long long
using namespace std;

int firstOccurence (vector<int>& A, int size, int x) {
    //base case 
    if (size == 0) return -1;

    int ans = firstOccurence(A, size - 1, x);

    if (ans != -1) return ans;

    else {
        if (A[size - 1] == x) return size;
        else return -1;
    }
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

    int ans = firstOccurence(A, n, x);

    cout << ans << endl;

}