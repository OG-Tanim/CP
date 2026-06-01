#include <bits/stdc++.h>
#define int long long
using namespace std;

void printCombinations(int index, int sum, int target, vector<int> &arr, vector<int> &path, vector<vector<int>> &ans) {
    
    //invalid cases
    if (index == arr.size() || sum > target) {
        return;
    }

    //base case
    if (sum == target) {
        ans.push_back(path);
        return;
    }

    //not take 
    printCombinations(index + 1, sum, target, arr, path, ans);

    //take and not move 
    path.push_back(arr[index]);
    printCombinations(index, (sum + arr[index]), target, arr, path, ans);
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
    
    int n, k; cin >> n >> k;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    vector<int> path; vector<vector<int>> ans;
    
    printCombinations(0, 0, k, A, path, ans);


    //print 
    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); i++) {

        cout << ans[i].size() << " ";

        for (int j = 0; j < ans[i].size(); j++) {

            cout << ans[i][j] << " ";
        }

        cout << endl;

    }

    cout << endl;

}