#include <bits/stdc++.h>
#define int long long
using namespace std;

void hanoi(int n, char src, char dest, char aux) {
    //base case
    if (n == 0) return;

    // move n - 1 src to aux using dest
    hanoi(n - 1, src, aux, dest);

    //print the move of src to dest
    cout << "Move " << src << " to " << dest << '\n';

    //now monve n - 1 from aux to dest using src
    hanoi(n - 1, aux, dest, src);
}

signed main () {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    hanoi(n, 'A', 'C', 'B'); //move from A to C using B
    
    cout << endl;
}