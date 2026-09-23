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
    tuple<bool, bool, TreeNode*> trav(TreeNode* now, TreeNode* p, TreeNode* q) {
        if(now==nullptr) return make_tuple(false, false, nullptr);

        auto [ax, bx, rx] = trav(now->left, p, q);
        auto [ax2, bx2, rx2] = trav(now->right, p, q);
        if(rx!=nullptr) return make_tuple(ax, bx, rx);
        if(rx2!=nullptr) return make_tuple(ax2, bx2, rx2);
        
        ax2 = ax|ax2|(now==p);
        bx2 = bx|bx2|(now==q);

        return make_tuple(ax2, bx2, (ax2&&bx2)?now:nullptr);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto [ax, bx, rx] = trav(root, p, q);
        return rx;
    }
};
