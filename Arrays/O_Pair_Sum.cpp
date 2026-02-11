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

            //check the sum with the each element that is not itself
                if (arr[i] + arr[j] == target) count++;
            
        }

        // cout << "after " << i << "iteration: " << count << endl;

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