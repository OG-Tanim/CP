#include <bits/stdc++.h>
#define int long long
using namespace std;

void printSequence(int i, int target, vector<int>& A, vector<int>& sequence, vector<vector<int>>& ans) {
    
    //invalid states
    if (i > A.size()) {
        return;
    }

    //base case
    if (i == A.size()) {   

        int sum = 0;
        for (int x: sequence) {
            sum += x;
        }

        if (sum == target) {
            ans.push_back(sequence);
        }
        return;
    }

    //make a choice
    //take the element 
    sequence.push_back(A[i]);

    //Recursive call for all sequences from this choice
    printSequence(i + 1, target, A, sequence, ans);

    //Undo
    sequence.pop_back();

    //make another choice
    //not taking
    printSequence(i + 1, target, A, sequence, ans);
    
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
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> sequence; vector<vector<int>> ans;
    printSequence(0, k, A, sequence, ans);


    //print 
    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++) {

        for (int j = 0; j < ans[i].size(); j++) {
            
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}