#include <iostream>
#include <vector>
using namespace std;

void solve() {
    
    int n;
    cin >> n;

    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int total = 0, avg = 0, max = arr[0], min = arr[0];
    
    for (int i = 0; i < n; i++) {
        total += arr[i];
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i]; 
    }
    //update average
    avg = total / n;
    cout << total << " " << max << " " << min << " " << avg;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}