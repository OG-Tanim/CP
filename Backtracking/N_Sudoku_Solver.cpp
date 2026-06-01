#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canPlace(char num, int row, int col, vector<vector<char>> &board) {

    //check row
    for (int i = 0; i < 9; i++) {

        if (board[row][i] == num) {
            return false;
        }
    }

    //check col 
    for (int i = 0; i < 9; i++) {

        if (board[i][col] == num) {
            return false;
        }
    }

    //check 3*3 grid
    int startingR = (row / 3) * 3;
    int startingC = (col / 3) * 3;
     
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (board[startingR + i][startingC + j] == num) {
                return false;
            }
        }
    }

    return true;
}

void sudokuSolver(int i, int j, vector<vector<char>> &board) {

    //Base Case: last row completed
    if (i == 9) {
        
        //print the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                cout << board[i][j];
            }
            cout << '\n';
        }

        cout << endl;
        return;
    }

    //if we reach the end of a row, move on to the next row
    if (j == 9) {
        sudokuSolver(i + 1, 0, board);     //nothing to change on the board
        return;
    }

    //if current cell is fixed move to the next cell
    if (board[i][j] != '.') {
        sudokuSolver(i, j + 1, board);     //nothng to change on the board
        return;
    }

    //try all options form 1-9 for each of the empty cells
    for (int n = 1; n <= 9; n++) {

        char charNum = (char)(n + '0');

        if (canPlace(charNum, i, j, board)) {

            board[i][j] = (char)(n + '0');

            sudokuSolver(i, j + 1, board);

            //undo
            board[i][j] = '.';
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    // int t = 1;
    // cin >> t

    // while(t--) {
    //     solve();
    // }

    vector<vector<char>> board (9, vector<char> (9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    sudokuSolver(0, 0, board);

}