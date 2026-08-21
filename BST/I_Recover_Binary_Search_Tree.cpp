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
    Exactly two nodes of the binary search tree had their values swapped by
    mistake. Recover the tree by swapping them back, without changing its
    structure. The function returns nothing -- fix the tree in place.
*/

struct Data {
    int first = 0; 
    int second = 0; 
};

Data inOrder(TreeNode* root, int &prev) {

    if (root == NULL) return Data(); 

    auto leftAns = inOrder(root -> left, prev);

    if (prev != INT_MIN and prev > root -> val) {

        if (leftAns.first == 0) leftAns.first = prev;
        leftAns.second = root -> val; 
    }
    
    prev = root -> val; 

    auto rightAns = inOrder(root -> right, prev); 

    Data ans;
    if (leftAns.first != 0) ans.first = leftAns.first; 
    else ans.first = rightAns.first; 

    if (leftAns.second != 0) ans.second = leftAns.second; 
    else ans.second = rightAns.second; 

    return ans; 
}

void recoverTree(TreeNode* root) {
    int prev = INT_MIN; 
    auto [rogue1, rogue2] = inOrder(root, prev);
    swap(rogue1, rogue2); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nodes(n);
    for (int i = 0; i < n; i++) cin >> nodes[i];

    TreeNode* root = buildTree(nodes);

    recoverTree(root);

    cout << serialize(root) << '\n';

    return 0;
}


//find the rogue element

//find it's appropriate place 
//prev node -> right = rogue node