#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e18; 

int f(int i, int j, int n, vector<vector<int>> &A, vector<vector<int>> &dpA) {

    if (i >= n or j >= n) return INF; 

    if (i == n - 1) return A[i][j]; 

    if (dpA[i][j] != -1) return dpA[i][j]; 

    //move down
    int ansDown = A[i][j] + f(i + 1, j, n, A, dpA);

    //move diagonal right
    int ansDiagonal = A[i][j] + f(i + 1, j + 1, n, A, dpA);

    return dpA[i][j] = min(ansDown, ansDiagonal);
}

void solve() {
    int n; cin >> n; 
    vector<vector<int>> A(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
             int elem; cin >> elem; 
             A[i].push_back(elem); 
        }
    }

    vector<vector<int>> dpA(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) { 
             dpA[i].push_back(-1); 
        }
    }

    int minCost = f(0, 0, n, A, dpA); 

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