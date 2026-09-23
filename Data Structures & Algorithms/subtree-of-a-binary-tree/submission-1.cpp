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
    bool isSameTree(TreeNode* base, TreeNode* sub){
        if(base==nullptr||sub==nullptr) return base==sub;

        bool l = isSameTree(base->left, sub->left);
        if(!l) return false;

        bool r = isSameTree(base->right, sub->right);
        if(!r) return false;

        return base->val==sub->val;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr) return false;

        bool cur = isSameTree(root, subRoot);
        if(cur) return true;

        
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot) ;
    }
};
