#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

int f(int pos, int n, vector<int> &A, vector<int> &dpA) {

    if (n == 1) return A[1]; 

    //we are returning the cost of a jump and the minimim cost of reaching n + 1 from the position jumped to 

    if (pos == n + 1) {
        return 0;                                             // n + 1 position has 0 cost in Total
    }

    if (dpA[pos] != -1) return dpA[pos]; 

    //jump 1 
    int costOf1 = A[pos + 1] + f(pos + 1, n, A, dpA);        //current postion cost + minCost of getting to n + 1   

    //for the last position (idx == n): A[n + 1] is set to 0 + the recursive call returns 0

    //jump 2
    int costOf2 = INT_MAX;                                  //for paths that jump to n + 2

    if (pos + 2 <= n + 1) costOf2 = A[pos + 2] + f(pos + 2, n, A, dpA); 

    //set dpA and return min Cost of both
     return dpA[pos] = min(costOf1, costOf2);    

}

void solve() {
    int n; cin >> n; 
    vector<int> A(n + 2, 0);  

    for (int i = 1; i <= n; i++) {
        cin >> A[i]; 
    }
    
    //memoise
    vector<int> dpA(n + 3, -1); 

    int minCost = f(0, n, A, dpA);

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