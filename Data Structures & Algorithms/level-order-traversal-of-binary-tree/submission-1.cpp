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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> v = {};
        queue<pair<TreeNode*, int>> trav;
        trav.emplace(root, 0);

        while(!trav.empty()){
            auto [nod, lvl] = trav.front();
            trav.pop();
            while(v.size() < (lvl+1)){
                v.emplace_back();
            }
            v[lvl].emplace_back(nod->val);
            
            if(nod->left != nullptr)
                trav.emplace(nod->left, lvl+1);
            if(nod->right != nullptr)
                trav.emplace(nod->right, lvl+1);
        }
        return v;
    }
};
