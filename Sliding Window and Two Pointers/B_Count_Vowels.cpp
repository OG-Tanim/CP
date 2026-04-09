#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isVowel (char c) {
    if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') || (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U')) {
        return true;
    }
    else return false; 
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    //set initial window's count 
    int count = 0;
    for (int i = 0; i < k; i++) {
        if (isVowel(s[i])) count += 1;
    }
    cout << count << " ";

    //left index
    int l = 0;

    //SLiding Window - shrink and expnad at the same time
    for (int r = k; r < n; r++) {

        if (isVowel(s[r])) count += 1;
        if (isVowel(s[l])) count -= 1;
        
        l++;
        cout << count << " ";
    }

    cout << endl; 

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
    }
}
