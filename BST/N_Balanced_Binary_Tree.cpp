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
    Return whether the binary tree is height-balanced, that is, whether the left
    and right subtrees of every node differ in height by no more than 1.
*/
struct Data {
    int height = 0; 
    bool isBalanced = true; 
}; 

Data helper(TreeNode* root) {

    if (root == NULL) return Data(); 

    auto leftAns = helper(root -> left);
    auto rightAns = helper(root -> right); 
    
    Data ans;  
    //udpate the height 
    ans.height = max(leftAns.height, rightAns.height) + 1;

    //if not balanced
    if (!leftAns.isBalanced || !rightAns.isBalanced || abs(leftAns.height - rightAns.height) > 1) {
        ans.isBalanced = false;
    }

    return ans; 
}

bool isBalanced(TreeNode* root) {

    if (root == NULL) return true; 

    return helper(root).isBalanced;  

}

int main() {                    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    bool ans = isBalanced(root);

    cout << (ans ? "true" : "false") << '\n';

    return 0;
}