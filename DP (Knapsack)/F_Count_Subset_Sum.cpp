#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int MOD_VAL = 1e9 + 7;

int f(int idx, int currSum, int target, int n, vector<int> &A, vector<vector<int>> &dpA) {
    //returns the number of subsets (paths once idx reach n) that have sum equal to the target

    if (idx == n) return (currSum == target ? 1 : 0); 

    if (dpA[idx][currSum] != -1) return dpA[idx][currSum];

    //take 
    int take = 0; 
    if (currSum + A[idx] <= target) {
        take = f(idx + 1, currSum + A[idx], target, n, A, dpA);
    }

    //don't take
    int notTake = f(idx + 1, currSum, target, n, A, dpA);

    //return sum of both
    return dpA[idx][currSum] = (take + notTake) % MOD_VAL; 
}

void solve() {
    int n, target; cin >> n >> target; 
    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }   

    //memoisation
    vector<vector<int>> dpA(n, vector<int> (target + 1, -1)); 

    int ans = f(0, 0, target, n, A, dpA);

    cout << ans; 
}  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}