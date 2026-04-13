#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    //Binary search
    for (int i = 0; i < q; i++) {
        int target;
        cin >> target;

        int lF = 0, rF = n - 1, lL = 0, rL = n - 1, ansF= -1, ansL = -1;
        
        //Binary search for First Occurence
        while (lF <= rF) {

            //calculate mid
            int mid = (lF + rF) / 2;

            if (A[mid] == target) {
                ansF = mid;
                
                //keep going on the left search to find the first occurance
                rF = mid - 1;
            }

            else if (A[mid] > target) {
                //left search
                rF = mid - 1;
            }
            else {
                //right search
                lF = mid + 1;
            }
        }

        //Binary search for Last Occurence
        while (lL <= rL) {

            //calculate mid
            int mid = (lL + rL) / 2;

            if (A[mid] == target) {
                ansL = mid;

                //keep goind on the right search to find the last occurance
                lL = mid + 1;
            }

            else if (A[mid] > target) {
                //left search
                rL = mid - 1;
            }
            else {
                //right search
                lL = mid + 1;
            }
        }

        if (ansF == -1) cout << 0 << endl;
        else cout << ansL - ansF + 1 << endl;
    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}