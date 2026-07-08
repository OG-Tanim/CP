#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string S; cin >> S; 
    int p; cin >> p;

    int cnt = 0, ans = -1;
    int n = S.size();

    //doesn't matter how many opening brackets are there before our target
    for (int i = p + 1; i < n; i++) {

        //track the opening brackets after our target
        if (S[i] == '(') {
            cnt++;
        } 
        if (S[i] == ')') {
            
            //cnt = 0: all opening brackets after our target has been paired
            if (cnt == 0) {
                ans = i;
                break;
            }

            //pair the closing brackets with opening brackets after our target
            cnt--;
        }
    }

    cout << ans;  
}

// void solve() {
//     string S; cin >> S; 
//     int n = S.size();

//     stack<int> st;
//     for (int i = 0; i < n; i++) {
//         char current = S[i];

//         if (current == '(') {
//             st.push(i);
//         }

//         if (current == ')') {
//             //it will make a pair with st top
//             cout << st.top() << ", " << i << '\n';
//             st.pop();
//         }
//     }

//     cout << endl;
// }

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}