#include <bits/stdc++.h>
#define int long long
using namespace std;

void printPath(int i, int j, int n, int m, string path, vector<vector<int>>& A) {

    //The following sequence is for starting out from the Initial Node: 1, 1; target points being (n, m)

    //Invalid States
    if (i > n || j > m || A[i-1][j-1] == 1) {
        return; 
    }

    //Base Case
    if (i == n && j == m) {
        cout << path << endl;
        return;
    }

    //We only have 2 choices at each node - move Right: (i, j + 1) or move Down: (i + 1, j) 

    //Move R:
    path += 'R';
    //recursively print all possible paths that start with 'R'
    printPath(i, j + 1, n, m, path, A);
    //Undo
    path.pop_back();

    //Move D:
    path += 'D';
    printPath(i + 1, j, n, m, path, A);
    path.pop_back();

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    // cin >> t

    // while(t--) {
    //     solve();
    // }

    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    string path = "";

    //starting state: 1, 1
    printPath(1, 1, n, m, path, A);
}