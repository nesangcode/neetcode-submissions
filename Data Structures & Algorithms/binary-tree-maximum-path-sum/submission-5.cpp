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
    unordered_map<TreeNode*, int> sub;
    int mx = INT_MIN;

    void pco(TreeNode* now, unordered_map<TreeNode*, int> &mp){
        if(now==nullptr) return;
        int mxx = now->val;
        if(now->left != nullptr){
            pco(now->left, mp);
            mxx = max(mxx, now->val+mp[now->left]);
        }
        if(now->right != nullptr){
            pco(now->right, mp);
            mxx = max(mxx, now->val+mp[now->right]);
        }

        sub[now] = mxx;
    }

    void trav(TreeNode* root, int up){
        vector<int> arr = {up, sub[root->left], sub[root->right]};
        sort(arr.begin(), arr.end());
        mx = max(mx, 
        max(root->val,
        max(root->val+arr[2], root->val+arr[2]+arr[1])));

        if(root->left != nullptr){
            trav(root->left,
            root->val+max(up, sub[root->right])
            );
        }

        if(root->right != nullptr){
            trav(root->right,
            root->val+max(up, sub[root->left])
            );
        }
    }
    int maxPathSum(TreeNode* root) {
        pco(root, sub);
        trav(root, 0);
        return mx;
    }
};
