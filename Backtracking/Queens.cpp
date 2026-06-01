#include <bits/stdc++.h>
#define int long long
using namespace std;

bool canPlace(int row, int col, vector<vector<char>> &board) {

    //upper col
    int i = row, j = col;
    while (i >= 0) {

        if (board[i][j] == 'Q') {
            return false;
        }

        i--;
    }

    //left upper diagonal 
    i = row, j = col;
    while (i >= 0 && j >= 0) {

        if (board[i][j] == 'Q') {
            return false;
        }

        i--;
        j--;
    }

    //right upper diagonal 
    i = row, j = col;
    while (i >= 0 && j < board.size()) {

        if (board[i][j] == 'Q') {
            return false;
        }

        i--;
        j++;
    }

    return true;

}

void placeQueens (int row, int n, vector<vector<char>> &board, vector<vector<vector<char>>> &ans) {

    //Base Cases
    if (row == n) {
        ans.push_back(board);
        return;
    }

    //make the choices: WE HAVE to PUT EXACTLY ONE queen at each ROW, ie., 
    //n cols for each row to place ONE queen so we Iterate THROUGH the columns as choices of putting queens 
    for (int col = 0; col < n; col++) {

        if (canPlace(row, col, board)) {

            board[row][col] = 'Q';                   

            placeQueens(row + 1, n, board, ans);

            board[row][col] = '.';

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

    int n; cin >> n; vector<vector<char>> board(n, vector<char> (n, '.'));
    vector<vector<vector<char>>> ans;

    placeQueens(0, n, board, ans);

    cout << ans.size() << '\n';

    for (int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < n; j++) {

            for (int k = 0; k < n; k++) {

                cout << ans[i][j][k];

            }

            cout << '\n';

        }

        cout << '\n';
    }

    cout << endl;

}