#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n; 
    
    queue<int> qi; 
    qi.push(0);
    int count = 0, ans = -1;  

    while(!qi.empty()) {
        int curr = qi.front(); 
        //pop curr; 
        qi.pop();

        //push current's next 2 options to the queue
        if (count < n) {
            qi.push(curr * 10 + 1); 
            count++; 
        }

        if (count < n) {
            qi.push(curr * 10 + 2); 
            count++; 
        }

        if (count == n) 
        {
            ans = qi.back();
            break; 
        }; 
    }

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