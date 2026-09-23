/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool trav(TreeNode* root, TreeNode* mn, TreeNode* mx){
        if(root==nullptr) return true;
        bool l = trav(root->left, mn, root);
        bool r = trav(root->right, root, mx);

        bool xl = !mn || (root->val > mn->val);
        bool xr = !mx || (root->val < mx->val);

        return l&&r&&xl&xr;
    }
    bool isValidBST(TreeNode* root) {
        return trav(root, nullptr, nullptr);
    }
};
