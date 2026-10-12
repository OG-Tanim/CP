#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7; 

int f(int step, int n, vector<int> &dpA) {

    if (step > n) return 0; //invalid path
    if (step == n) {
        //1 path found 
        return 1;  
    }

    if (dpA[step] != -1) return dpA[step]; 

    //the choices we have at each node: 1 or 2 step
    int ans1 = f(step + 1, n, dpA) % mod;                     //no. of paths if we take 1 step
    int ans2 = f(step + 2, n, dpA) % mod;                     //no. of paths if we taek 2 steps at this node

    return dpA[step] = (ans1 + ans2) % mod;                     //total paths at this nodes is memoized
    
}

void solve() {
    int n; cin >> n; 
    vector<int> dpA(n, -1); 

    int ans = f(0, n, dpA);

    for (auto x: dpA) {
        cout << x << endl; 
    }
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