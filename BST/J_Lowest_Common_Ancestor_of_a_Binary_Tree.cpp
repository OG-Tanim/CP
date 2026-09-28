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
    if (root == nullptr) return nullptr;
    vector<TreeNode*> st;
    st.push_back(root);
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
    Return the lowest common ancestor of the nodes p and q: the lowest node in
    the tree that has both p and q as descendants (a node may be a descendant
    of itself).
*/

bool searchBTree(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return false; 
    if (root == p || root == q) return true; 
    return searchBTree(root -> left, p, q) || searchBTree(root -> right, p, q); 
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    // if (root == NULL) return NULL; 
        
    //     //if root is one element, just check whether left of right tree has the other and return root
    //     if (root == p || root == q) {
    //         if (searchBTree(root -> left, p, q) || searchBTree(root -> right, p, q)) return root; 
    //     }

    //     if (searchBTree(root -> left, p, q) and searchBTree(root -> right, p, q)) return root; 

    //     auto leftAns = lowestCommonAncestor(root -> left, p, q); 
    //     if (leftAns) return leftAns; 

    //     return lowestCommonAncestor(root -> right, p, q); 

    //This basically a modified SEARCH
    //if root of the tree is one of the elements, it's our answer
    if (root == NULL || root == p || root == q) return root;  

    //if not, ask BOTH sides to bring their search answers: if any of the elements are present there just 
    auto leftAns = lowestCommonAncestor(root -> left, p, q);
    auto rightAns = lowestCommonAncestor(root -> right, p, q);

    //both sides have elements means root is answer; 
    if (leftAns and rightAns) return root; 
    //else root is not - the side which has it is 
    return leftAns ? leftAns : rightAns; 
     
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

    cout << lowestCommonAncestor(root, p, q)->val << '\n';

    return 0;
}