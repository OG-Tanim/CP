#include <bits/stdc++.h>
#define int long long
using namespace std;

void printParentheses(int opening, int closing, int n, string& sequence, vector<string>& ans) {

    //base case: always produce 2n sequnece
    if (opening == n && closing == n) {   

        ans.push_back(sequence);

        return;
    }

    //make a choice: start with opening brackets smaller than n as there can't be more than n 
    if (opening < n) {
        
        sequence += '(';
        printParentheses(opening + 1, closing, n, sequence, ans);
        sequence.pop_back();

    }

    //make another choice: take closing brackets only when they are smaller in number
    if (opening > closing) {

        sequence += ')';
        printParentheses(opening, closing + 1, n, sequence, ans);
        sequence.pop_back();

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    // cin >> t

    // while(t--) {
    //     solve();
    // }

    int n; cin >> n;
    vector<int> A(n);

    string sequence; vector<string> ans;
    printParentheses(0, 0, n, sequence, ans);


    //print 
    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++) {

        cout << ans[i] << '\n';

    }

    cout << endl;

}