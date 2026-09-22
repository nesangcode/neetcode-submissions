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
    void trav(TreeNode* now){
        if(now==nullptr) return;
        trav(now->left);
        trav(now->right);
        swap(now->left, now->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        trav(root);
        return root;
    }
};
