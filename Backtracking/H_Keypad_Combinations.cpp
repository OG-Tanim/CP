#include <bits/stdc++.h>
#define int long long
using namespace std;

void printSequence(int index, string &S, map<char, string> keypad, string &sequence, vector<string> &ans) {

    //baseCase
    if (index == S.size()) {

        ans.push_back(sequence);
        return;

    }

    //Backtracking 
    char digit = S[index];
    string choices = keypad[digit];

    //Recursive call for each option at each node

    for (char x: choices) {

        sequence += x;
        printSequence(index + 1, S, keypad, sequence, ans);  //udpating the index selects options for that specific node 
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

    string s; cin >> s;
    map<char, string> keypad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    string sequence; vector<string> ans;
    printSequence(0, s, keypad, sequence, ans);


    //print 
    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++) {

        cout << ans[i] << '\n';

    }

    cout << endl;

}