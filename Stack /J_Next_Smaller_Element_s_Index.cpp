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

    stack<int> st; //will hold indexes this time 
    vector<int> ans(n); //answers will be in reverse order 

    for (int i = n - 1; i >= 0; i--) {

        //remove useless elements (top is greater than current elem -> current elem can cover for all elems on the left as top could but and more)
        while (!st.empty() && A[st.top()] >= A[i]) {
            st.pop();
        }

        //empty means to elem smaller than current to the right
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }

        //must push all elems even if it is bigger as it can be next smaller to some elem on the left than st.top
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) cout << 'X' << " ";
        else              cout << ans[i] << " ";
    }

    cout << endl; 
}  

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    while(t--) {
        solve();
    }
}