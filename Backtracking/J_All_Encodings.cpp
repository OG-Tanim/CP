#include <bits/stdc++.h>
#define int long long
using namespace std;

char toAlphabet(int number) {
    return ('a' + (number - 1));
}

void printEncodings(int index, string &str, string &path, vector<string> &ans) {

    //base case
    if (index == str.size()) {
        
        ans.push_back(path);
        return;
    }

    //invalid State: we can't take 0 individually nor can we start a 2 digit number with 0: so sequence stops 
    if (str[index] == '0') {
        return;
    }

    //take 1 digit:
    int digit = stoi(str.substr(index, 1)); //stringTOInteger(substring)
    char ch = toAlphabet(digit);

    path += ch;
    printEncodings(index + 1, str, path, ans);
    path.pop_back();

    //take 2 digits
    if (index < (str.size() - 1)) {
        
        int digits = stoi(str.substr(index, 2));

        if (digits >= 10 && digits <= 26) {

            char ch2 = toAlphabet(digits);

            path += ch2;
            printEncodings(index + 2, str, path, ans);
            path.pop_back();

        }
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

    string path; vector<string> ans;
    
    printEncodings(0, s, path, ans);

    //print 
    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++) {

        cout << ans[i] << '\n';

    }

    cout << endl;

}