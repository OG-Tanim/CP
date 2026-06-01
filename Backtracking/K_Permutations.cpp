#include <bits/stdc++.h>
#define int long long
using namespace std;

void printPermutations(vector<int> &A, vector<bool> &used, vector<int> &path, vector<vector<int>> &ans) {
    
    if (path.size() == A.size()) {
        ans.push_back(path);
        return;
    }

    //make choices
    for (int i = 0; i < A.size(); i++) {

        if (used[i] == false) {

            //take
            path.push_back(A[i]);
            used[i] = true;

            printPermutations(A, used, path, ans);

            //undo
            used[i] = false;
            path.pop_back();

        }

    }
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    // cin >> t

    // while(t--) {
    //     solve();
    // }

    int n; cin >> n; vector<int> A(n);

    for (int i = 0; i < n; i++) {
            cin >> A[i];
    }

    vector<bool> used(n, false); vector<int> path; vector<vector<int>> ans;

    printPermutations(A, used, path, ans);

    //print 
    cout << ans.size() << '\n';

    for(int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < ans[i].size(); j++) {

            cout << ans[i][j] << " ";

        }

        cout << '\n';

    }

    cout << endl;

} 