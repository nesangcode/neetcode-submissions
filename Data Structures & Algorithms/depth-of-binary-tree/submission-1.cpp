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
    TreeNode* revn(TreeNode* now, TreeNode* prev, TreeNode* target){
        if(now==nullptr) return nullptr;
        if(now==target){
            now->left = prev;
            return target;
        }
        auto nl = revn(now->left, now, target);
        auto nr = revn(now->right, now, target);
        if(nl==target){
            now->left = prev;
            return target;
        } else if(nr==target){
            now->right = prev;
            return target;
        }
        return nullptr;
    }
    pair<int, TreeNode*> trav(TreeNode* now, TreeNode* prev){
        if(now==nullptr) return {0, prev};
        auto [tl, nl] = trav(now->left, now);
        auto [tr, nr] = trav(now->right, now);
        if(tl>tr){
            return {(prev!=nullptr)+tl, nl};
        } else {
            return {(prev!=nullptr)+tr, nr};
        }
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        auto [tx, nx] = trav(root, nullptr);
        return tx+1;
        revn(root, nullptr, nx);
        auto [tf, nf] = trav(nx, nullptr);
        return tf;
    }
};
