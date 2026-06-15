#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {

    int n; cin >> n; vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    //frequency array of elements 
    vector<int> freq(101);
    for (int i = 0; i < n; i++) {
        freq[A[i] + 50]++;
    }

    //Print the sorted elemetns in reverse to get the largest num
    for (int i = 0; i <= 100; i++) { 
        while(freq[i]--) {
            cout << i - 50 << " ";
        }
    }
    
    cout << endl;

}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}  