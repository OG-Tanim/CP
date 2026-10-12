#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int f(int idx, int n, vector<int> &A, vector<int> &dpA) {
    //this funtion return the MAX PROFIT from current idx to n - 1

    //base case 
    if (idx >= n) return 0; 

    if (dpA[idx] != -1) return dpA[idx]; 

    //take 
    int take = A[idx] + f(idx + 2, n, A, dpA);     // if we take current pos, we make a jump of 2 

    //don't take 
    int notTake = f(idx + 1, n, A, dpA);          // if we don't take, we can move to the next position

    return dpA[idx] = max(take, notTake); 
}

void solve() {
    int n; cin >> n;
    vector<int> A(n); 
    
    for (int i = 0; i < n; i++) {
        cin >> A[i]; 
    }

    if (n == 1) {
        cout << A[0] << endl; 
        return; 
    }

    // Solution - return the max( [0, n - 2], [1, n - 1] ) 

    //memoisation
    vector<int> dpA1 (n, -1); 
    vector<int> dpA2 (n, -1); 

    int ans1 = f(0, n - 1, A, dpA1); 
    int ans2 = f(1, n, A, dpA2); 

    int maxProfit = max(ans1, ans2);                     //state: idx ONLY

    cout << maxProfit << endl; 
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