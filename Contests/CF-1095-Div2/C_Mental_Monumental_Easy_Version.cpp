#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll n; cin >> n;
    vector<int> A;

    for(ll i = 0; i < n; i++) {
        ll elem;
        cin >> elem;
        A.push_back(elem);
    } 

    sort(A.begin(), A.end());
    ll mex = 0;
    set<int> mexSet;

    for (ll i = 0; i < n; i++) {
        if (A[i] / 2 >= mex) {
            if (!(mexSet.contains(mex))) {
                mex++;
                while (mexSet.contains(mex)) {
                    mex++;
                }
            }
            cout << "at " << A[i] << "mex is " << mex << endl; 
        }
        else if (A[i] >= mex) mexSet.insert(A[i]);
    }

    cout << mex << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t; cin >> t;
    while(t--) {
        solve();
    } 
}
