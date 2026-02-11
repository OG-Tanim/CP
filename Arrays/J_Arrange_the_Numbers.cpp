
#include <iostream>

using namespace std;

void solve() {
    
    int n;
    
    while (cin >> n) {
        
        int arr[n];
        
        int l = 0; //right index of Array
        int r = n - 1; //left index of Array
        
        int number = 1; //Value 
        
        // //cross condition: i == j for even and i < j for odd
        // while (l <= r) {
            
        //     arr[l] = number;
        //     if (number != n) number++;  //stop for odd numbers before updating
            
        //     arr[r] = number;
        //     number++;
            
        //     l++;
        //     r--;
        // }
        
        for (int i = 1; i <= n; i++) {
            
            if (i % 2 != 0) {
                arr[l] = i;
                l++;
            }
            else {
                arr[r] = i;
                r--;
            }
        }
        
        //iterating through array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << ((i != n - 1) ? " ": "");
        }
        
        cout << endl;
    }
}

int main() {
    // your code goes here
    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++) {
        solve();
    }
}