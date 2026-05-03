#include <bits/stdc++.h>
using namespace std;
#define int long long

bool checkIthBit(int n, int i) {
    int mask = 1LL << i;
    if ((n & mask) == 0) return false;
    else                 return true;

} 

void solve() {
    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int diffPosition = -1; //the position on which the single elements will differ, ie, bit at that positon in xor of the array will be 1 
    int xor_A = 0;        //basically XOR of rogue1 and 2 where their differing bits will ouput 1.

    for (int x: A) {
        xor_A ^= x;
    }

    for (int i = 0; i < 31; i++) {
        if (checkIthBit(xor_A, i) == 1) 
        {
            diffPosition = i;
            break;
        }
    }
    //two groups based on the differing bit - that bit is set: rogue1's group of odd number of elements - else that bit is unset - rogue2's group of odd number of elements - easily do XOR to find out the rogue's in each group
    int rogue1 = 0, rogue2 = 0;   

    for (int i = 0; i < n; i++) {
        if (checkIthBit(A[i], diffPosition) == 1) 
        {
            rogue1 ^= A[i];
        }
        else rogue2 ^= A[i];
    } 

    if (rogue1 < rogue2) cout << rogue1 << " " << rogue2;
    else                 cout << rogue2 << " " << rogue1;

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