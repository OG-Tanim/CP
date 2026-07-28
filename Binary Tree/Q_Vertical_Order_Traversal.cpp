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
    Return the vertical order traversal: one list per column, from the
    leftmost column to the rightmost.
*/
vector<vector<int>> verticalTraversal(TreeNode* root) {

    unordered_map<int, vector<pair<int, int>>> verticalMap; //{ col: [{level, val}]}
    int col = 0, level = 1; 
    queue<tuple<TreeNode*, int, int>> q; //{node, level, col}
    int minCol = col, maxCol = col; 

    q.push({root, level, col}); 
    while(!q.empty()) {

        auto [curr, level, col] = q.front();
        q.pop(); 
        
        verticalMap[col].push_back({ level, curr -> val });
        minCol = min(col, minCol);
        maxCol = max(col, maxCol);

        if (curr -> left != NULL) q.push({ curr -> left, level + 1, col - 1});
        if (curr -> right != NULL) q.push({ curr -> right, level + 1, col + 1});
    }

    //Vertical Column wise map created
    vector<vector<int>> ans;
    for (int i = minCol; i <= maxCol; i++) {

        auto arr = verticalMap[i]; 
        sort(arr.begin(), arr.end());  //sorting based on level first then val 

        vector<int> a; 
        for (auto [level, val]: arr) {
            a.push_back(val);
        }
 
        ans.push_back(a);
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

    vector<vector<int>> ans = verticalTraversal(root);

    for (auto& col : ans) {
        for (int i = 0; i < (int)col.size(); i++) {
            if (i) cout << " ";
            cout << col[i];
        }
        cout << '\n';
    }

    return 0;
}