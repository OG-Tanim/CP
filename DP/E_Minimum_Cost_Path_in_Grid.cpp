#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e18;

int f(int i, int j, int n, int m, vector<vector<int>> &A, vector<vector<int>> &dpA) {

    if (i >= n or j >= m) {
        return INF;                        //for discarding invalid paths
    }

    if (i == n - 1 and j == m - 1) {
        return A[i][j]; 
    }

    if (dpA[i][j] != -1) return dpA[i][j]; 
    
    //move right
    int ansR = A[i][j] + f(i, j + 1, n, m, A, dpA);              //cost of current pos + min cost to reach destination from the next pos

    //move down
    int ansD = A[i][j] + f(i + 1, j, n, m, A, dpA);

    return dpA[i][j] = min(ansR, ansD); 
}

void solve() {
    int n, m; cin >> n >> m; 
    vector<vector<int>> A(n, vector<int>(m)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j]; 
        }
    }

    vector<vector<int>> dpA(n, vector<int>(m, -1)); 

    int minCost = f(0, 0, n, m, A, dpA); 

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