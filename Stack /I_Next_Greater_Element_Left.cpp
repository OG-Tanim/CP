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

    //traversal
    for (int i = 0; i < n; i++) {
        
        //remove useless elements: when st.top is smaller than the current elem
        while (!st.empty() && st.top() <= A[i]) {
            st.pop();
        }

        //else st.top or empty is ans
        if (st.empty()) cout << 'X' << " ";
        else            cout << st.top() << " ";

        //must push all elements (top may be invalid, but the elem itself can be the greater elem for some elem on the right)
        st.push(A[i]);
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