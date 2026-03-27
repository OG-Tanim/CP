#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, target;
    cin >> n >> target;
    set<int>preSumSet;
    bool answer = false;
    int preSum = 0;

    //Prefix SUM
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        preSum += elem;

        //for Sub-arrays from the index = 0 - (L = 0): P[R] = target - when we find the target itself in the prefix Sum Array 
        if (preSum == target) {
            answer = true;
            break;
        }
        /*
        for Sub-arrays that don't start from index = 0 -  (L != 0): P[R] - p[L - 1] = target
        P[R] - target = P[L - 1] - index P[L] to P[R] is the subarray
        */
        if (preSumSet.contains(preSum - target)) {
            answer = true;
            break;
        }
        
        preSumSet.insert(preSum);
    }
    cout << ((answer) ? "YES" : "NO") << endl;
}

signed main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}   