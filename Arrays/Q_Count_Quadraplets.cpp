#include <iostream>

using namespace std;

void solve() {

    int n, target;

    cin >> n >> target;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    //iterate through the array 
    for (int i = 0; i < n; i++) {

        //iterate again
        for (int j = i + 1; j < n; j++) {
            
            //iterate again
            for (int k = j + 1; k < n; k++) {
                
                //iterate again
                for (int l = k + 1; l < n; l++) {

                    if (arr[i] - 2 * arr[j] + 3 * arr[k ] - 4 * arr[l] == target) count++;  
                }
            }

        }

    }

    cout << count << endl;
}

int main() {
    // your code goes here
    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}