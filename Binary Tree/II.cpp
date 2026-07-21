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

// ================= STUDENT FUNCTION =================
vector<vector<long long>> levelOrder(TreeNode* root) {
    // write your code here
    if (root == NULL) return {}; 

    queue<TreeNode*> q; 
    vector<vector<long long>> ans; 
    q.push(root); 

    while(!q.empty()) {
        vector<long long> level; 
        int sz = q.size(); 
        
        for (int i = 0; i < sz; i++) {

            auto curr = q.front(); 
            q.pop(); 
            level.push_back(curr -> val);

            if (curr -> left) q.push(curr -> left);
            if (curr -> right) q.push(curr -> right);
        }

        ans.push_back(level); 
    }

    return ans; 

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

    vector<vector<long long>> ans = levelOrder(root);

    for (auto &level : ans) {
        for (int i = 0; i < level.size(); i++) {
            if (i) cout << " ";
            cout << level[i];
        }
        cout << '\n';
    }
}