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
    vector<int> fin;
    void trav(TreeNode* now){
        if(now==nullptr) return;
        fin.emplace_back(now->val);
        trav(now->left);
        trav(now->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        trav(root);
        return fin;
    }
};