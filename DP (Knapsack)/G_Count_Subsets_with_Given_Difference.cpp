#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int f(int idx, int currSum, int target, int n, vector<int> &A, vector<vector<int>> &dpA) {
    //returns the number of paths(subset when idx reaches n) that is eqaul to target
    if (idx == n) return ((currSum == target) ? 1 : 0);

    if (dpA[idx][currSum] != -1) return dpA[idx][currSum]; 

    //take 
    int take = ((currSum + A[idx]) <= target) ? f(idx + 1, currSum + A[idx], target, n, A, dpA) : 0;
    
    //don't take
    int notTake = f(idx + 1, currSum, target, n, A, dpA);

    return dpA[idx][currSum] = (take + notTake); 
}

void solve() {
    int n, d; 
    cin >> n >> d;
    vector<int> A(n);

    int sum = 0; 
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i]; 
    }

    //            we need, S1 - S2 = D              
    //                     S1 = S2 + D
    //
    //            AND      S1 + S2 + D = Sum + D   [given S1, S2 comprise all the elems of array]
    //                     S1 + S1     = Sum + D
    //                     S1          = (Sum + D) / 2

    // So, we need to find subset S1 == Sum + D / 2 - the rest of the elems automatically form S2

    //if sum + d is odd no valid pair available
    if ((sum + d) & 1) {
        cout << 0 << endl; 
        return;
    }

    int target = (sum + d) / 2;

    vector<vector<int>> dpA(n, vector<int> (target + 1, -1));

    int ans = f(0, 0, target, n, A, dpA); 

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