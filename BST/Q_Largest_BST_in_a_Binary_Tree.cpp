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
    Return the number of nodes in the largest subtree of the given binary tree
    that is itself a valid Binary Search Tree.
*/
struct Data {
    bool isBST = true; 
    int size = 0; 
    int largestBST = 0; 
    int mn = INT_MAX; 
    int mx = INT_MIN; 
}; 

Data solve(TreeNode* root) {

    if (root == NULL) return Data();
    
    auto leftAns = solve(root -> left); 
    auto rightAns = solve(root -> right);

    Data ans; 

    ans.isBST = leftAns.isBST and rightAns.isBST and (leftAns.mx < root -> val) and (rightAns.mn > root -> val); 

    ans.size = leftAns.size + rightAns.size + 1; 

    ans.mn = min({ root -> val, leftAns.mn, rightAns.mn}); 
    ans.mx = max({ root -> val, leftAns.mx, rightAns.mx }); 

    if (ans.isBST) {
        ans.largestBST = ans.size;
    } else {
        ans.largestBST = max(leftAns.largestBST, rightAns.largestBST); 
    }

    return ans; 

}   


int largestBst(TreeNode* root) {
    return solve(root).largestBST; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << largestBst(root) << '\n';

    return 0;
}