#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, target;
    cin >> n >> target;

    map<int, int>preSumMap;
    int preSum = 0;
    int count = 0;

    //Prefix SUM
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        preSum += elem;
        //for Sub-arrays from the index = 0 - (L = 0): P[R] = target - when we find the target itself in the prefix Sum Array 
        if (preSum == target) {
            count++;
        }
        /*
        for Sub-arrays that don't start from index = 0 -  (L != 0): P[R] - p[L - 1] = target
        P[R] - target = P[L - 1] - index P[L] to P[R] is the subarray
        */
        if (preSumMap.contains(preSum - target)) {
            count += preSumMap[preSum - target];
        }
        
        preSumMap[preSum]++;
    }
    cout << count << endl;
}

signed main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}   