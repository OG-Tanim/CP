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

TreeNode* findNode(TreeNode* root, int val) {
    vector<TreeNode*> st;
    if (root) st.push_back(root);
    while (!st.empty()) {
        TreeNode* nd = st.back();
        st.pop_back();
        if (nd->val == val) return nd;
        if (nd->left)  st.push_back(nd->left);
        if (nd->right) st.push_back(nd->right);
    }
    return nullptr;
}

/*
    Implement only the function below.
    Return the lowest common ancestor of the nodes p and q in the given binary
    search tree (a node may be a descendant of itself).
*/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    while (root != NULL) {

        if (p -> val < root -> val && q -> val < root -> val)       root = root -> left; 
        else if (p -> val > root -> val && q -> val > root -> val)  root = root -> right; 

        //else either one of p, q is equal to root or the SPLIT POINT in the BST is found
        else return root; 
    }

    return NULL; 

    //Time Complexity: O(H) - in a balanced BST which is log₂N and N in a skewed BST
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    int pv, qv;
    cin >> pv >> qv;

    TreeNode* root = buildTree(nodes);
    TreeNode* p = findNode(root, pv);
    TreeNode* q = findNode(root, qv);

    TreeNode* ans = lowestCommonAncestor(root, p, q);

    cout << ans->val << '\n';

    return 0;
}