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
    Return the top view of the binary tree (left to right).
*/

bool isLeaf(TreeNode* node) {
    return node -> left == NULL and node -> right == NULL;
}

void addLeftMostNodes(TreeNode* node, vector<int> &ans) {
    
    auto curr = node; 
    while (curr) {

        if (!isLeaf(curr)) ans.push_back(curr -> val);

        if (curr -> left != NULL) curr = curr -> left; 
        else curr = curr -> right;
    }
}

void addRightMostNodes(TreeNode* node, vector<int> &ans) {

    auto curr = node; vector<int> temp; 
    while (curr) {
        if (!isLeaf(curr)) temp.push_back(curr -> val);

        if (curr -> right != NULL) curr = curr -> right;
        else curr = curr -> left; 
    }

    for (int i = temp.size() - 1; i >= 0; i--) {
        ans.push_back(temp[i]);
    }
}

void addLeafNodes(TreeNode* node, vector<int> &ans) {
    //DFS
    if (node == NULL) return; 

    if (isLeaf(node)) ans.push_back(node -> val); 

    //fist add the left subtree leaves
    addLeafNodes(node -> left, ans);

    //then add the right subtree leaves
    addLeafNodes(node -> right, ans);
}

vector<int> topView(TreeNode* root) {

    if (root == NULL) return {};

    vector<int> ans; 
    if (!isLeaf(root)) ans.push_back(root -> val);

    //left Boundary : first should always be on the left
    addLeftMostNodes(root -> left, ans);

    //Leaf Nodes
    addLeafNodes(root, ans);

    //right boundary: fist should always be on the right
    addRightMostNodes(root -> right, ans);

    return ans; 
     
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    vector<int> ans = topView(root);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}