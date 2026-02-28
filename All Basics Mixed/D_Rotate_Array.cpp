#include <iostream>;
#include <vector>;
using namespace std;

void solve() {
    int n, lShift;
    cin >> n;
    vector<int> arrIn(n), arrOut(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arrIn[i];
    }

    cin >> lShift;

    for (int i = 0; i < n; i++) {

        if (i < lShift) arrOut[n - lShift + i] = arrIn[i];

        else arrOut[i - lShift] = arrIn[i];    //shift lShift postions 
    }

    for (int i = 0; i < n; i++) {
        cout << arrOut[i] << " "; 
    }

    cout << endl;

}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}