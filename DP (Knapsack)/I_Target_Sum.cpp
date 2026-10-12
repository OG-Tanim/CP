#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int INF = -2000; 

int f(int idx, int currSum, int target, int sum, vector<int> &A, vector<vector<int>> &dpA) {
    //returns number of paths (subsets when idx reaches n) that has sum equal to target for each node

    if (idx == A.size()) {
        return (((currSum) == target) ? 1 : 0);         //we started currSum 1000 instead of 0
    }; 

    if (dpA[idx][currSum + sum] != INF) return dpA[idx][currSum + sum]; 

    // place +ve before current elem
    int add = f(idx + 1, currSum + A[idx], target, sum, A, dpA); 
    
    // place -ve before current elem 
    int deduct = f(idx + 1, currSum - A[idx], target, sum, A, dpA);

    //save and return the number of paths that equal to target from current node
    return dpA[idx][currSum + sum] = (add + deduct); 
}

void solve() {
    int n, target; cin >> n >> target;                                   
    vector<int> A(n); 
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
        sum += A[i]; 
    }

    //MEMOISATION : states = { idx, currSum }
    vector<vector<int>> dpA(n, vector<int>(2 * sum + 1, INF));          //dpA: { INF: not visited, sum's range [-sum, sum] }
    int idx = 0, currSum = 0;                                     

    //have to check all the subsets' sums
    int ans = f(idx, currSum, target, sum, A, dpA);                            //states: idx, currSum

    cout << ans << endl; 

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