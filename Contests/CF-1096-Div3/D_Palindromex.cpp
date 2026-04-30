#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int len = 2 * n;
    vector<int> a(len);
    
    // Read the array and locate the two occurrences of 0
    int p1 = -1, p2 = -1;
    for (int i = 0; i < len; ++i) {
        cin >> a[i];
        if (a[i] == 0) {
            if (p1 == -1) p1 = i;
            else p2 = i;
        }
    }

    int max_mex = 0;

    // Lambda to expand palindrome from a given center and update max_mex
    auto check_center = [&](int L_start, int R_start) {
        if (L_start > R_start) return;
        
        int l = L_start, r = R_start;
        // Expand outwards as long as it remains a valid palindrome
        while (l >= 0 && r < len && a[l] == a[r]) {
            l--;
            r++;
        }
        
        // Step back to the last valid palindrome boundaries
        l++;
        r--;
        
        if (l > r) return;
        
        // Calculate MEX for the found palindromic subarray
        vector<bool> present(n + 1, false);
        for (int i = l; i <= r; ++i) {
            if (a[i] <= n) {
                present[a[i]] = true;
            }
        }
        
        int mex = 0;
        while (present[mex]) {
            mex++;
        }
        
        // Maximize the answer
        if (mex > max_mex) {
            max_mex = mex;
        }
    };

    // Check the 3 mandatory centers
    check_center(p1, p1);                             // Centered at the first 0
    check_center(p2, p2);                             // Centered at the second 0
    check_center((p1 + p2) / 2, (p1 + p2 + 1) / 2);   // Centered strictly between the two 0s

    cout << max_mex << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}