#include <iostream>

using namespace std;

void solve() {

    int n, target;

    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    int count = 0;

    //iterate through the array 
    for (int i = 0; i < n; i++) {

        //iterate again
        for (int j = i + 1; j < n; j++) {
            
            //iterate again
            for (int k = j + 1; k < n; k++) {
                
                if (arr[i] + arr[j] + arr[k] == target) {
                    count++;
                }
            }

        }

    }

    cout << count << endl;
}

int main() {
    // your code goes here
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}