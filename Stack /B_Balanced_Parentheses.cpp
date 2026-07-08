#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isValid(char open, char close) {

    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') || 
            (open == '[' && close == ']')   
    );
}

//For mutiple types of brackets
void solve() {

    string S; cin >> S; 
    stack<char> st;

    bool ans = true; 
    for (char ch: S) {

        //if opening bracket, push to stack 
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }

        //if closing bracket, it has to pair with the opening bracket on top of stack
        else {

            //there is no opening bracket left to pair with
            if (st.empty()) {
                ans = false;
                break; 
            }

            else {
                //is valid : a -> opening and b -> closing
                if (isValid(st.top(), ch)) {
                    st.pop();
                }
                else {
                    ans = false; 
                    break; 
                }
            }
        }
    }

    //if stack still not empty, there is one or more unmatched opening brackets
    if (!st.empty()) ans = false;

    cout << (ans ? "Yes" : "No") << '\n';

}  

//solve for a single type of brackets;
// void solve () {
//     string S; cin >> S; 
//     int count = 0;

//     bool ans = true; 
//     for (char ch: S) {

//         if (ch == '(') {
//             count++;
//         }

//         else {
//             //no opening bracket left to pair closing bracket with
//             if (count == 0) {
//                 ans = false;
//                 break;
//             }
//             else {
//                 count--;
//             }
//         }
//     }

//     //if there are still upaired opening brackets left
//     if (count != 0) ans = false;

//     cout <<  (ans ? "Yes" : "No") << endl;
// }

signed main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // int t = 1;
    int t; 
    cin >> t;
    while(t--) {
        solve();
    }  
}
