#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

bool f(int idx, int currSum, int target, int n, vector<int> &A, vector<vector<int>> &dpA) {
    // return true if the full path, idx reached n (subset) sum == target 

    if (idx == n) return currSum == target; 

    if (dpA[idx][currSum] != -1) return dpA[idx][currSum]; 

    //take
    bool take = false; 
    if (currSum + A[idx] <= target) {
        take = f(idx + 1, currSum + A[idx], target, n, A, dpA); 
    }

    //notTake
    bool notTake = f(idx + 1, currSum, target, n, A, dpA);

    // return true if either is true
    return dpA[idx][currSum] = (take or notTake); 
}

void solve() {
    int n; cin >> n; 
    vector<int> A(n); 
    int sum = 0; 
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
        sum += A[i]; 
    } 
    
    //Solution: key point is both subsets comprise all the elements of the array 
    //                      sum 1 + sum 2 = full sum 
    //                if,   sum 1 == sum 2
    //                      sum 1 == full sum / 2 
    //so, we just have to find one subset that sums to full sum / 2, the rest of elements will the form other subset required

    if (sum & 1) {
        cout << "NO" << endl; 
        return;                 //odd number cannot be split into 2 equla whole numbers
    } 

    int target = sum / 2; 

    //memoisation
    vector<vector<int>> dpA (n, vector<int> (target + 1, -1));              // -1: not visited, 0: false, 1: true

    bool ans = f(0, 0, target, n, A, dpA);                                 //states: idx, currSum

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