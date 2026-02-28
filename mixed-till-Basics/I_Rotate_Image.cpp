#include <iostream>;
#include <vector>;
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> arrIn(n, vector<int>(n));
    vector<vector<int>> arrOut(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arrIn[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        
        int offset = n - 1;
        for (int j = n - 1; j >= 0; j--) {
            arrOut[i][j - offset] = arrIn[j][i];
            offset -= 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arrOut[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}