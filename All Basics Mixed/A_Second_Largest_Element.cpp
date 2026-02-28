#include <iostream>;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sMax = -1;
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    //2nd largest distinct element
    for (int i = 0; i < n; i++) {
        
        if (arr[i] > sMax and arr[i] < max) {
            //if this exists more than once
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i]) count++; 
            }
            if (count < 2) {
                sMax = arr[i];
            }
            
        }
    }

    cout << sMax;
}

int main() {
    int t = 1;
    // cin >> t;

    for (int i = 0; i < t; i++) {
        solve();
    }
}