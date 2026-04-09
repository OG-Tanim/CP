#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>A;

    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        A.push_back(elem);
    }

    //good numbers
    set<int>gdNums;
    for (int i = 0; i < m; i++) {
        int elem;
        cin >> elem;
        gdNums.insert(elem);
    }

    int count = 0;
    
    for (int i = 0; i < k; i++) {
        if (gdNums.contains(A[i])) count++;
    }   
    cout << count << " ";

    //left index
    int l = 0;

    //SLiding Window (Fixed Size) - shrink and expnad at the same time
    for (int r = k; r < n; r++) {

        if (gdNums.contains(A[r])) count++;
        if (gdNums.contains(A[l])) count--;

        cout << count << " ";

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
