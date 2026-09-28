#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Serialize a tree to its level-order (BFS) form: values separated by single
// spaces, "null" for a missing child, trailing "null"s trimmed. Empty -> "".
string serialize(TreeNode* root) {
    if (!root) return "";
    vector<string> out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* nd = q.front();
        q.pop();
        if (!nd) { out.push_back("null"); continue; }
        out.push_back(to_string(nd->val));
        q.push(nd->left);
        q.push(nd->right);
    }
    while (!out.empty() && out.back() == "null") out.pop_back();
    string res;
    for (size_t i = 0; i < out.size(); i++) {
        if (i) res += ' ';
        res += out[i];
    }
    return res;
}

/*
    Implement only the function below.
    `inorder` and `postorder` are the inorder and postorder traversals of the same
    binary tree (all values distinct). Construct that tree and return its root.
*/
TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd) {

    if (inStart > inEnd) return NULL; 

    int currRoot = postorder[postEnd]; 
    auto root = new TreeNode(currRoot); 

    int idx = -1; 
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == currRoot) {
            idx = i; 
            break; 
        }
    }
    int rightHalfLength = inEnd - idx; 
    
    root -> left = helper(inorder, postorder, inStart, idx - 1, postStart, postEnd - 1 - rightHalfLength);
    root -> right = helper(inorder, postorder, idx + 1, inEnd, postEnd - rightHalfLength, postEnd - 1); 

    return root; 
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = postorder.size(); 
    return helper(inorder, postorder, 0, n - 1, 0, n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> inorder(n), postorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];

    TreeNode* root = buildTree(inorder, postorder);

    cout << serialize(root) << '\n';
    return 0;
}