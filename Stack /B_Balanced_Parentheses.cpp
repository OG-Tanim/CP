#include <bits/stdc++.h>
using namespace std;

#define int             long long
#define all(x)          x.begin(), x.end()
#define double          long double
#define endl            '\n'
#define ff              first
#define ss              second
#define v               vector
#define pb              push_back
#define bit(num, i)     (num & (1ll << i))

using pii = pair<int, int>;
const bool multipleTestCases = false;

void solve()
{
    string s; 
    int cnt = 0;
    bool ans =  true;  

    for (char c: s) {

        if (c == '(' || c == '{' || '[') {
            cnt++;
        }
        else {
            //if there are NO unpaired opening brackets left
            if (cnt == 0) {
                ans = false; 
                break;
            }
            
            cnt--;
        }
    }

    //if there are unpaired opening brackets left
    if (cnt != 0) ans = false;

    cout << (ans ?) << endl;

}  

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}