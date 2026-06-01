#include <bits/stdc++.h>
#define int long long
using namespace std;

void printSequence(int currStair, int target, int maxStep, vector<int>& path ) {

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
    
    //make a Choice: this time make our choices 1 by 1 from 1 to K
    for (int i = 1; i <= maxStep; i++) {

        //print all sequences for each of the choices
        path.push_back(i);
        printSequence(currStair + i, target, maxStep, path);
        path.pop_back();

    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // int t = 1;
    // cin >> t

    // while(t--) {
    //     solve();
    // }
    int n, k; cin >> n >> k;

    vector<int> path;

    printSequence(0, n, k, path);
}