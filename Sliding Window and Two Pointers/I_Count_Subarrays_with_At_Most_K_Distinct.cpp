#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int>A;
     
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        A.push_back(elem);
    }

    //left index
    int l = 0, count = 0;
    //using Map as Subarrays can contain duplicates
    map<int, int>freqMap;

    //Sliding Window (dynamic size) : update l and r on conditions
    for (int r = 0; r < n; r++) {
        freqMap[A[r]] += 1;

        // right index gets updated in each turn and l updates as long as the window is INVALID
        while (freqMap.size() > k) {

            freqMap[A[l]] -= 1;

            if (freqMap[A[l]] < 1) freqMap.erase(A[l]);

            l++;
        }
        //if valid window - no. of subarrays in [l, r]: r - l + 1 for each window
        count += (r - l + 1);
    }
    cout << count << endl; 

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}
