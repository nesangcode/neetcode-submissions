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
    tuple<int, int, bool> trav(TreeNode* root){

        tuple<int, int, bool> central;
        bool isInit = false;
        if(root->left != nullptr){
            auto [mn, mx, res] = trav(root->left);
            if(mx >= root->val || !res) return tuple(0, 0, false);
            isInit = true;
            central = tuple(mn, mx, res);
        }

        if(root->right != nullptr){
            auto [mn, mx, res] = trav(root->right);
            if(mn <= root->val || !res) return {0, 0, false};
            if(!isInit){
                isInit = true;
                central = tuple(mn, mx, res);
            } else {
                get<0>(central) = min(get<0>(central), mn);
                get<1>(central) = max(get<1>(central), mx);
            }
        }

        if(!isInit){
            isInit = true;
            central = tuple(root->val, root->val, true);
        } else {
            get<0>(central) = min(get<0>(central), root->val);
            get<1>(central) = max(get<1>(central), root->val);
        }

        return central;
    }

    bool isValidBST(TreeNode* root) {
        auto [mn, mx, res] = trav(root);

        return res;
    }
};
