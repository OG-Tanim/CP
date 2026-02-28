#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arrIn(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arrIn[i][j];
        }
    }

    int sR = 0, eR = n - 1;
    int sC = 0, eC = m - 1;

    while (sR <= eR && sC <= eC) {
        //Top Row
        for (int j = sC; j <= eC; j++) 
        {
            cout << arrIn[sR][j] << " ";
        }

        //Right Column
        for (int i = sR + 1; i <= eR; i++) 
        {
            cout << arrIn[i][eC] << " ";
        }

        //Bottom Row - only if it's not equal to the first Row
        if (sR != eR) {
            for (int j = eC - 1; j >= sC; j--) 
            {
                cout << arrIn[eR][j] << " ";
            }
        }

        //Right Column - only if it's not equal to the left Column
        if (sC != eC) {
            for (int i = eR - 1; i >= sR + 1; i--) 
            {
                cout << arrIn[i][sC] << " ";
            }
        }

        //update the params
        sR++;
        eR--;
        sC++;
        eC--;
    }

}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}