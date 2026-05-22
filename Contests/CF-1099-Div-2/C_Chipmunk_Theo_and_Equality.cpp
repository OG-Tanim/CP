#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n; 
    cin >> n;

    vector<int> a(n);
    int max_val = 0;
    for (int &x : a) {
        cin >> x;
        max_val = max(max_val, x);
    }

    int limit = max_val + 2;
    vector<int> total_steps(limit, 0);
    vector<int> reach_count(limit, 0);
    
 
    vector<int> visited(limit, -1);

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int steps = 0;

        while (true) {
      
            if (visited[x] != i) {
                visited[x] = i;
                reach_count[x]++;
                total_steps[x] += steps;
            }

            if (x == 1) {
                x = 2;
                steps++;
                if (visited[x] != i) {
                    visited[x] = i;
                    reach_count[x]++;
                    total_steps[x] += steps;
                }
                break;
            }

            if (x % 2 == 0) {
                x /= 2;
            } else {
                x++;
            }
            steps++;
        }
    }

    int ans = LLONG_MAX;

  
    for (int v = 1; v < limit; v++) {
        if (reach_count[v] == n) {
            ans = min(ans, total_steps[v]);
        }
    }

    if (ans == LLONG_MAX) {
        cout << -1 << "\n"; 
    } else {
        cout << ans << "\n";
    }
}

signed main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}