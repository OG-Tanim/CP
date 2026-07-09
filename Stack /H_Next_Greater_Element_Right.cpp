#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; 
    cin >> n; 
    vector<int> A(n); 
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    stack<int> st;
    vector<int> ans(n); //for storing answer in reverse
    //reverse traversal
    for (int i = n - 1; i >= 0; i--) {

        //remove useless elements
        while (!st.empty() && st.top() <= A[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }

        //must push all elements (even if the elem is smaller, it can be the greater next for elements smaller than itself)
        st.push(A[i]);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            cout << 'X' << " ";
        }
        else cout << ans[i] << " "; 
    }

    cout << endl;
}  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    while(t--) {
    // cin >> t;
        solve();
    }
}