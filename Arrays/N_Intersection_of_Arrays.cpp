#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int arr1[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    int m; 
    cin >> m;
    
    int arr2[m];
    
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    
    //iterating throuh the 1st input array
    for (int i = 0; i < n; i++) {
        
        // 2nd input array one for common element check
        for (int j = 0; j < m; j++) {
        
            if (arr1[i] == arr2[j]) {
                
                cout << arr1[i] << " "; // print on match

                arr2[j] = -1e9; //change the index's vlaue in the 2nd input array so that it doesn't match again 
                break;
            }
        }
        
    }
    cout << endl;
}

int main() {
    // your code goes here
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}