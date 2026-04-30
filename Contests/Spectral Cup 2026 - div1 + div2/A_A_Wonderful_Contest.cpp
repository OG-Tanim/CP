#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        w[i] = 100 / a; // Calculate points per subtask
    }
    
    // Sort step sizes in ascending order
    sort(w.begin(), w.end());
    
    long long max_reach = 0;
    for (int i = 0; i < n; i++) {
        // If the step is too large to bridge the gap, it's impossible
        if (w[i] > max_reach + 1) {
            cout << "No\n";
            return;
        }
        // Otherwise, this problem successfully extends our continuous range by 100
        max_reach += 100;
    }
    
    cout << "Yes\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}