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
    vector<int> v;
    void trav(TreeNode* raw){
        if(raw==nullptr) return;
        trav(raw->left);
        v.emplace_back(raw->val);
        trav(raw->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        v.reserve(100);
        trav(root);
        return v;
    }
};