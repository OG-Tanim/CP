#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    long long val;
    TreeNode *left, *right;
    TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoll(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* cur = q.front();
        q.pop();

        if (nodes[i] != "null") {
            cur->left = new TreeNode(stoll(nodes[i]));
            q.push(cur->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            cur->right = new TreeNode(stoll(nodes[i]));
            q.push(cur->right);
        }
        i++;
    }
    return root;
}

long long treeMax(TreeNode *root) {

    if (root == NULL) return LLONG_MIN;
    
    long long leftMax = treeMax(root -> left); 
    long long rightMax = treeMax(root -> right); 

    long long prev = max(leftMax, rightMax); 

    long long ans = max(prev, root -> val);
    
    return ans; 
}


// ================= STUDENT FUNCTION =================
long long maxOfTree(TreeNode* root) {
      // write your code here
      long long maxVal = treeMax(root); 

      return (maxVal == LLONG_MIN ? 0 : maxVal); 
}
// ====================================================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    cout << maxOfTree(root) << '\n';
}