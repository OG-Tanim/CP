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
vector<int> topView(TreeNode* root) {
    //Vertical Columwise Needed
    unordered_map<int, vector<int>> colwiseMap;   //{col: [vals]}
    //level order traversal 
    queue<pair<TreeNode*, int>> q;       // {node, col}
    int col = 0, minCol = 0, maxCol= 0;

    q.push({root, col}); 
    while(!q.empty()) {

        auto [curr, col] = q.front();
        q.pop();

        colwiseMap[col].push_back(curr -> val);
        minCol = min(minCol, col);
        maxCol = max(maxCol, col);

        if (curr -> left != NULL) q.push({curr -> left, col - 1});
        if (curr -> right != NULL) q.push({curr -> right, col + 1});

    }
    
    vector<int> ans; 
    for (int i = minCol; i <= maxCol; i++) {

        auto a = colwiseMap[i];
        ans.push_back(a[0]);

    }

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