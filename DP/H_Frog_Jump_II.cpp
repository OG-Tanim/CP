#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int f(int i, int n, int k, vector<int> &A, vector<int> &dpA) {

    //the controller never reacher invalid states where i >= n - handled by the out of bounds idx chceks; 

    if (i == n - 1) return 0;                                        //no cost of reaching n - 1 from n - 1

    //memoisation happens only once for each idx 
    if (dpA[i] != -1) return dpA[i]; 

    //jumping from 1 to K and returning the min val of them all 

    int minCost = INFINITY;                                 

    for (int j = 1; j <= k; j++) {

        //check for out of bounds idxs (discarding paths that jump over destination: idx >= n)
        if (i + j <= n - 1) {

            int totalCost = abs(A[i + j] - A[i]) + f(i + j, n, k, A, dpA);              //cost of jumping to i + j stone added with minCost of reaching n - 1 from i + jth idx
            //update minCost
            minCost = min(totalCost, minCost); 
        }
    }   

    //set dpA for current idx and return the min cost from current position/idx
    return dpA[i] = minCost; 
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n);  
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }  

    vector<int> dpA(n + 1, -1);

    int minCost = f(0, n, k, A, dpA);                                  //starting from idx 0

    cout << minCost << endl; 
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