// Given an integer N and an integer D, rotate the binary representation of the integer N by D digits to the left as well as right and return the results in their decimal representation after each of the rotation.
// Note: Integer N is stored using 16 bits. i.e. 12 will be stored as 0000000000001100. Output array should follow {leftrotation, rightrotation}.


#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, d; cin >> n >> d;

    int rotationFactor = d % 16, originalN = n;

    //left rotation
    for (int i = 0; i < rotationFactor; i++) {

        //if we find the rightmost index to be 1
        if ((n & (1 << 15)) != 0) {

            //left shift one step
            n <<= 1;

            //set the rightmost bit
            n |= 1;

        }

        else n <<= 1;

    }

    //right rotation
    for (int i = 0; i < rotationFactor; i++) {

        //left most element is 1
        if ((originalN & 1) != 0) {

            //right shift
            originalN >>= 1;
            //set the leftmost bit
            originalN |= (1 << 15);
        }

        else originalN >>= 1;

    }

    cout << n << " " << originalN;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // cin >> t;
    while(t--) {
        solve();
    }
} 