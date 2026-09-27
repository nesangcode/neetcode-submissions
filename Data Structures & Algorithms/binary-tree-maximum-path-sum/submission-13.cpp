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

    int trav(TreeNode* root){
        if(root==nullptr) return 0;
        vector<int> arr = {trav(root->left), trav(root->right)};
        if(arr[0]>arr[1]) swap(arr[0], arr[1]);
        int mxv=max(root->val,
        max(root->val+arr[1], root->val+arr[1]+arr[0]));
        int mx2=max(root->val, root->val+max(arr[0], arr[1]));
        mx = max(mx, mxv
        );
        return mx2;
    }
    int maxPathSum(TreeNode* root) {
        trav(root);
        return mx;
    }
};
