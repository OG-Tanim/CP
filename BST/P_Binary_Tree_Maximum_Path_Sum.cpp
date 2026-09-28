#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < (int)nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoi(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < (int)nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoi(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

/*
    Implement only the function below.
    Return the maximum path sum of any non-empty path in the tree.
*/
struct Data {
    int straightPathSum = INT_MIN; 
    int maxSumTillCurr = INT_MIN; 
};

Data solve(TreeNode* root) {

    if (root == NULL) return Data(); 

    auto leftAns = solve(root -> left);
    auto rightAns = solve(root -> right);

    //just not taking negetive paths
    leftAns.straightPathSum = max(0, leftAns.straightPathSum);
    rightAns.straightPathSum = max(0, rightAns.straightPathSum);

    Data ans; 
    ans.straightPathSum = root -> val + max(leftAns.straightPathSum, rightAns.straightPathSum); 
    ans.maxSumTillCurr = max({ (root -> val + leftAns.straightPathSum + rightAns.straightPathSum), leftAns.maxSumTillCurr, rightAns.maxSumTillCurr });

    return ans; 
}

int maxPathSum(TreeNode* root) {
    return solve(root).maxSumTillCurr; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << maxPathSum(root) << '\n';

    return 0;
}