#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string S;
    cin >> S;
     
    //left index
    int l = 0, len = 0;
    //using Map as Subarrays can contain duplicates
    map<char, int>freqMap;

    //Sliding Window (dynamic size) : update l and r on conditions
    for (int r = 0; r < n; r++) {
        freqMap[S[r]] += 1;

        // right index gets updated in each turn and l updates as long as the window is INVALID
        while (freqMap.size() > k) {

            freqMap[S[l]] -= 1;

            if (freqMap[S[l]] < 1) freqMap.erase(S[l]);

            l++;
        }
        //if valid window
        len = max(len, r - l + 1);
    }
    cout << len << endl; 

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
