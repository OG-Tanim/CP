#include <bits/stdc++.h>
#define int long long
using namespace std;

void printSequence(int i, int n, vector<int>& A, vector<int>& sequence) {
    
    //invalid states
    if (i > n) {
        return;
    }

    //base case
    if (i == n) {

        for (int x: sequence) {
             cout << x << " ";
        }

        cout << endl;

        return;
    }

    //make a choice
    //take the element 
    sequence.push_back(A[i]);

    //Recursive call for all sequences from this choice
    printSequence(i + 1, n, A, sequence);

    //Undo
    sequence.pop_back();

    //make another choice
    //not taking
    printSequence(i + 1, n, A, sequence);
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    // cin >> t

    // while(t--) {
    //     solve();
    // }

    int n; cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> sequence;
    printSequence(0, n, A, sequence);

}