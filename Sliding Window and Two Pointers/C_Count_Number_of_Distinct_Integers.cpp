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

    //Frequency map to track distinct elements
    map<int, int>freqMap;

    for (int i = 0; i < k; i++) {
        freqMap[A[i]] += 1;
    }   
    cout << freqMap.size() << " ";

    //left index
    int l = 0;

    //SLiding Window (Fixed Size) - shrink and expnad at the same time
    for (int r = k; r < n; r++) {

        freqMap[A[r]] += 1;
        freqMap[A[l]] -= 1;

        //if elemment becomes zero - remove
        if (freqMap[A[l]] < 1) freqMap.erase(A[l]);
        cout << freqMap.size() << " ";

        l++;
    }

    cout << endl; 

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
