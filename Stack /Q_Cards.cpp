#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n; 
    queue<int> q;
    
    for (int i = 1; i <= n; i++) {
        q.push(i); 
    }

    cout << "Discarded cards: "; 

    while (q.size() > 1) 
    {
        int front = q.front(); 
        q.pop();

        cout << front << " "; 

        q.push(q.front()); 
        q.pop(); 
    }

    cout << '\n' << "Remaining card: " << q.front() << endl; 
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