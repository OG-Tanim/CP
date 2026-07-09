#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s; cin >> s; 
    int k; cin >> k; 
    
    //stack: <char, length of continuous grouop> 
    stack<pair<char, int>> st;
    //traverse, create continuous groups and remove k-sized groups
    for (char ch: s) {
        //push
        if (st.empty() || st.top().first != ch) {
            st.push({ch, 1});
        }

        //update
        else {
            st.top().second++;
        }

        //remove
        if (st.top().second == k) {
            st.pop();
        }
    }

    string ans;
    while(!st.empty()) {

        auto [ch, n] = st.top();
        //pop
        st.pop();
        while (n--) {
            ans += ch;
        }
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