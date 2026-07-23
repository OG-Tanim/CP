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
    Return whether the binary tree is a mirror of itself (symmetric).
*/

bool isMirror(TreeNode *p, TreeNode *q) {

    if (p == NULL and q == NULL) return true; 
    if (p == NULL or q == NULL) return false; 

    //if both are not NULL, check for Mirror Symmatry
    bool leftAns = isMirror(p -> left, q -> right);
    bool rightAns = isMirror(p -> right, q -> left); 

    return (p -> val == q -> val) and leftAns and rightAns; 
}

bool isSymmetric(TreeNode* root) {

    if (root == NULL) return true; 

    return isMirror(root -> left, root -> right); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    bool ans = isSymmetric(root);

    cout << (ans ? "true" : "false") << '\n';

    return 0;
}