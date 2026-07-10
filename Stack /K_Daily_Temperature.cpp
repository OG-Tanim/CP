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
    //reverse traversal
    for (int i = n - 1; i >= 0; i--) {

        //removal on current is grater than stacktop as curr can cover for all elems on right
        while(!st.empty() && A[st.top()] <= A[i]) {
            st.pop();
        }

        //if empty no next greater elem for current
        if (st.empty()) {
            ans[i] = i;
        }
        else {
            ans[i] = st.top();
        }

        //if current is smaller we push, bigger we push as well 
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] - i << " ";
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