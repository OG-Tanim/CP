#include <bits/stdc++.h>
#define int long long
using namespace std;

void printPaths(int i, int j, int n, vector<vector<int>> &A, vector<vector<int>> &visited, string &path, vector<string> &ans) {

    //Invalid cases 
    if (i == n  || j == n || i < 0 || j < 0 || A[i][j] == 0 || visited[i][j] == 1) {
        return;
    }

    //base cases 
    if (i == n - 1 && j == n - 1) {
        ans.push_back(path);
        return;
    }

    //mark the current position as VISITED
    visited[i][j] = 1;

    //make the choices 
    //down 
    path += 'D';
    printPaths(i + 1, j, n, A, visited, path, ans);
    path.pop_back();

    //left 
    path += 'L';
    printPaths(i, j - 1, n, A, visited, path, ans);
    path.pop_back();

    //right
    path += 'R';
    printPaths(i, j + 1, n, A, visited, path, ans);
    path.pop_back();

    //up
    path += 'U';
    printPaths(i - 1, j, n, A, visited, path, ans);
    path.pop_back();

    //All options explored: mark this index as unVISITED
    visited[i][j] = 0;
  
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    // cin >> t

    // while(t--) {
    //     solve();
    // }

    int n; cin >> n; vector<vector<int>> A(n, vector<int>(n)), visited(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    string path; vector<string> ans;

    printPaths(0, 0, n, A, visited, path, ans);

    //print 
    cout << ans.size() << '\n';

    for(int i = 0; i < ans.size(); i++) {

        cout << ans[i] << '\n';

    }

    cout << endl;

}