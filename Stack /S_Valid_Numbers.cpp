#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    vector<int> a(10); 
    for (int i = 0; i < 10; i++) 
    {
        cin >> a[i]; 
    }   
    int n; cin >> n; 
    
    vector<int> integers; 
    for (int i = 0; i < 10; i++) 
    {
        if (a[i] == 1) {
            integers.push_back(i); 
        }
    }
 
    queue<string> q; 
    int i = 0; 
    for (int x: integers) 
    {
        if (x != 0) q.push(to_string(x)); 
    }
    while (!q.empty() && i < n) 
    {
        auto front = q.front(); 
        q.pop(); 
        i++; 

        cout << front << '\n'; 

        for (int x: integers) 
        {
            q.push(front + (to_string(x))); 
        }
    }

    cout << endl; 
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