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
    int mx = INT_MIN;

    int trav(TreeNode* &root){
        if(root==nullptr) return 0;

        int l = trav(root->left);
        int r = trav(root->right);
        
        int mxv=max(root->val,
        max(root->val+max(r,l), root->val+l+r));
        int mx2=max(root->val, root->val+max(r, l));
        mx = max(mx, mxv);
        return mx2;
    }
    int maxPathSum(TreeNode* root) {
        trav(root);
        return mx;
    }
};
