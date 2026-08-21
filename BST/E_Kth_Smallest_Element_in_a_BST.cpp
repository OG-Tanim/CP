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
    Return the k-th smallest value (1-indexed) in the BST.
*/
void inOrder(TreeNode* root, int k, int &c, int &ans) {

    if (root == NULL) return; 

    inOrder(root -> left, k, c, ans);

    //curr
    c++; 
    if (c == k) {
        ans = root -> val; 
        return; 
    }

    inOrder(root -> right, k, c, ans);
}

int kthSmallest(TreeNode* root, int k) {
    //Inorder Traversal
    int counter = 0; 
    int ans = 0; 

    inOrder(root, k, counter, ans); 

    return ans; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    int k;
    cin >> k;

    TreeNode* root = buildTree(nodes);

    cout << kthSmallest(root, k) << '\n';

    return 0;
}