#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<vector<int>>arr(n, vector<int>(m));

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    if (found) return;
    //left Column
    for (int i = n - 1; i >= 0; i--) {

        if (arr[i][0] != -1) cout << arr[i][0] << " ";
        else 
        {
            found = true;
            break;
        } 
    }
    if (found) return;
    //top Row
    for (int j = 1; j < m; j++) {
        
        if (arr[0][j] != -1) cout << arr[0][j] << " ";
        else 
        {
            found = true;
            break;
        } 
    }
    if (found) return;
    //right Column
    if (n != 1) {
        for (int i = 1; i < n; i++) {

        if (arr[i][m - 1] != -1) cout << arr[i][m - 1] << " ";
        else 
        {
            found = true;
            break;
        } 
    }
    if (found) return;
    //bottom Row
    if (n != 1 && m != 1) {
        for (int j = m - 2; j > 0; j--) {
            
            if (arr[n - 1][j] != -1) cout << arr[n - 1][j] << " ";
            else 
            {
                found = true;
                break;
            } 
        }
    }
    if (found) return;
    }
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}