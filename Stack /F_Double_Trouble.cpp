#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

    string s;
    cin >> s; 

    stack<char> st;
    for (char ch: s) {

        //push
        if (st.empty() || ch != st.top()) {
            st.push(ch);
        }
        //if matches remove
        else {
            st.pop();
        }
    }

    //ans as st is in reverse
    string ans; 
    while (!st.empty()) 
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;
    
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