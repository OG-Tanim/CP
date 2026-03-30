#include<bits/stdc++.h>
using namespace std;

#define int long long

bool isBalanced(vector<int>& vCount, vector<int>& cCount, string& s, int l, int r) {

    int vowels = ((l == 0) ? vCount[r] : vCount[r] - vCount[l - 1]);
    int consonents = ((l == 0) ? cCount[r] : cCount[r] - cCount[l - 1]);

    return vowels == consonents;
}

void solve() {
    
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> vCount(n), cCount(n);
    int vSum = 0, cSum = 0;
    for (int i = 0; i < n; i++) {

        if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
            vSum++;
        } 
        else cSum++;

        vCount[i] = vSum;
        cCount[i] = cSum;
    }
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        cout << ((isBalanced(vCount, cCount, s, l, r) ? "YES" : "NO")) << '\n';
    }
    cout << endl;
}

signed main()
{
    int t = 1;
    // cin >> t;

    while(t--)
    {
        solve();
    }
}
