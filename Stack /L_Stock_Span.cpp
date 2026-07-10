#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    //Find Next Greater Element to the right   
    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //stack to strore indexes
    stack<int> st; vector <int> ans(n);
    //traversal
    for (int i = 0; i < n; i++) {
        //if we find current to be bigger than top means it can cover for all the previous top could - so remove
        while (!st.empty() && A[st.top()] <= A[i]) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }

        //smaller current can also be some i's next bigger on the left side
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << i - ans[i] << " ";
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