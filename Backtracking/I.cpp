#include <bits/stdc++.h>
#define int long long
using namespace std;

void printSequence(int currStair, int target, vector<int>& path ) {

    //The following sequence is for starting out from the Initial Node: 0

    //Base Case
    if (currStair == target) {
        for (int x: path) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    //Invalid States
    if (currStair > target) {
        return; 
    }
    
    //make a Choice: jump of 1
    path.push_back(1);

    //Recursive call explores all the porssibilites of starting with 1: prints all the possibile sequences
    printSequence(currStair + 1, target, path);

    //Undo the choice
    path.pop_back();

    //Now make another choice: jump of 2
    path.push_back(2);
    printSequence(currStair + 2, target, path);
    path.pop_back();

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

    vector<int> path;

    printSequence(0, n, path);
}