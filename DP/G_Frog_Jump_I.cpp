#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const int POSTITVE_INF = 1e18; 

int f(int i, int n, vector<int> & A, vector<int> & dpA) {

    //Invalid paths where i reacher idx n, is handled in the check from 2 step jump 

    if (i == n - 1) return 0;                                          //there is no cost of reching n - 1 form n -1; 

    //Memoisation
    if (dpA[i] != -1) return dpA[i]; 

    //jump 1 stone
    int costOf1 = abs(A[i + 1] - A[i]) + f(i + 1, n, A, dpA);         //cost of going to i + 1 added min cost of goind from i + 1 to n - 1

    //jump 2 stones
    int costOf2 = POSTITVE_INF;                                       //for discarding invalid paths    

    if (i + 2 <= n - 1) costOf2 = abs(A[i + 2] - A[i]) + f(i + 2, n, A, dpA);

    //set dpA[i]: min cost of reaching n - 1 from i and return 
    return dpA[i] = min(costOf1, costOf2); 
}

void solve() {
    int n; cin >> n;
    vector<int> A(n);  
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }  

    vector<int> dpA(n + 1, -1);

    int minCost = f(0, n, A, dpA);                                  //starting from idx 0

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