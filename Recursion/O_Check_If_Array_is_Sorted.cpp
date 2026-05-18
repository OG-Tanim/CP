#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isSorted (vector<int>& A, int size) {
    //base case 
    if (size == 1) return true;

    bool previousAns = isSorted(A, size - 1);

    if (!previousAns) return false;
    
    if (A[size - 1] < A[size - 2]) return false;
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

    bool ans = isSorted(A, n);

    cout << (ans ? "YES" : "NO") << endl;

}