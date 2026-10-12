#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int f(int idx, int currSum, int sum, int n, vector<int> &A, vector<vector<int>> &dpA) {
    //returns absolute difference of a path (subset S1: when idx reaches n) and it's compliment S2

    if (idx == n) {
        return abs((2 * (currSum) - sum)); 
    }

    if (dpA[idx][currSum] != -1) return dpA[idx][currSum];

    // take 
    int take = f(idx + 1, currSum + A[idx], sum, n, A, dpA);

    // not take
    int notTake = f(idx + 1, currSum, sum, n, A, dpA);

    // minimum one is saved and returned
    return dpA[idx][currSum] = min(take, notTake);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    int sum = 0; 
    int maxElem = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i]; 
        maxElem = max(maxElem, A[i]); 
    }

    // Key Point: S1, S2 subsets comprise all the (NON NEGETIVE) elements of the array (2 partitions)
    // we need find out the sum of all the sunbsets(S1), then each subset's compliment (S2 which is the sum of all the other elems) is going to be:
    //                                  S2 = SUM - S1
    //              we need to minimize | S1 - S2 | 
    //                                  | S1 - SUM + S1 |
    //                         minimize | 2S1 - SUM |
    // at the end each subset we get S1, then we can just check for the above condition

    //MEMOISATION: states = { idx, currSum }
    int idx = 0, currSum = 0; 

    vector<vector<int>> dpA(n, vector<int> (n * maxElem + 1, -1));

    int ans = f(idx, currSum, sum, n, A, dpA);                   

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