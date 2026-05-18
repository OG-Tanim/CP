#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s; 
    cin >> s;
    int n = s.size();

    int total_13 = 0;
    for (char c : s) {
        if (c == '1' || c == '3') {
            total_13++;
        }
    }

    // Track the maximum number of valid elements we can KEEP
    // Default choice: Keep all '1's and '3's, delete all '2's and '4's
    int max_kept = total_13; 
    
    int current_2 = 0;
    int current_13 = 0;

    // Iterate through the string to find the optimal split point
    for (char c : s) {
        if (c == '2') {
            current_2++;
        } else if (c == '1' || c == '3') {
            current_13++;
        }

        // At this split point:
        // We keep all '2's seen so far (left side)
        // We keep all remaining '1's and '3's (right side)
        int kept = current_2 + (total_13 - current_13);
        max_kept = max(max_kept, kept);
    }

    // Minimum deletions = Total length - Maximum elements we can safely keep
    // This automatically handles deleting all '4's as well
    cout << n - max_kept << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}