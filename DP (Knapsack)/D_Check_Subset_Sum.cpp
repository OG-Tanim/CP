#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

bool f(int idx, int currSum, int target, int n, vector<int> &A, vector<vector<int>> &dpA) {
    //returns true or flase if currSum == target after reaching n for all paths (subsets)

    if (idx == n) return currSum == target; 

    if (dpA[idx][currSum] != -1) return dpA[idx][currSum]; 

    //take curr pos
    bool take = false; 
    if ( currSum + A[idx] <= target) { 

        take = f(idx + 1, currSum + A[idx], target, n, A, dpA);   //no letting currSum go out of bounds of dpA
    }
    
    //dont't take 
    bool notTake = f(idx + 1, currSum, target, n, A, dpA);

    //return true if either is true
    return dpA[idx][currSum] = (take or notTake); 
}

void solve() {
    int n, target; cin >> n >> target;                                   
    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    //memoisation
    vector<vector<int>> dpA(n, vector<int>(target + 1, -1));          //dpA: { -1: not visited, 0: false, 1: true }

    //have to check all the subsets' sums
    bool ans = f(0, 0, target, n, A, dpA);                            //states: idx, currSum

    cout << (ans ? "YES" : "NO") << endl; 

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