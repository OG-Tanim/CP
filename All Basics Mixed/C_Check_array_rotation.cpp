#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int min = arr[0], minIndex = 0;  //min Index gives us the values of right shift
    

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            minIndex = i;
            min = arr[i];
        }
    }

    cout << minIndex << endl;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}