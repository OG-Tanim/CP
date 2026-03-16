#include <iostream>
using namespace std;

void solve() {
    int n, q, l, r;
    cin >> n;

    string s;
    cin >> s;

    //prefix sum array - we consider only contribution of an element which is counter as 1 & if it is a vowel
    int sum = 0;
    int p[n];

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') sum ++;
        p[i] = sum;
    }

    //querry ranges
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        l--;
        r--;

        if (l == 0) cout << p[r];
        else cout << p[r] - p[l - 1];
        cout << endl;
    }
}

int main() {
    int t = 1;
    //cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}