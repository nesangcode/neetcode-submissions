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
    int res = -1;
    int nth(TreeNode* now, int &k, int b){
        int ln = (now->left==nullptr)?0:nth(now->left, k, b);
        if(k==(b+ln+1)) res = now->val;
        int rn = (now->right==nullptr)?0:nth(now->right, k, b+ln+1);
        return ln+rn+1;
    }

    int kthSmallest(TreeNode* root, int k) {
        nth(root, k, 0);
        return res;  
    }
};
