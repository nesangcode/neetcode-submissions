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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> idx;
        for(int i = 0; i < inorder.size(); i++){
            idx[inorder[i]] = i;
        }

        int nowi = idx[preorder[0]];
        TreeNode* head = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(head);

        for(int i = 1; i < preorder.size(); i++){
            TreeNode* last = nullptr;
            while(!st.empty()){
                TreeNode* tp = st.top();
                if(idx[tp->val] <= idx[preorder[i]]){
                    last = tp;
                    st.pop();
                } else {
                    break;
                }                
            }
            TreeNode* nn = new TreeNode(preorder[i]);
            if(last==nullptr){
                if(st.empty()) return nullptr;
                st.top()->left = nn;
            } else {
                if(last->right != nullptr) return nullptr;
                last->right = nn;
            }
            st.push(nn);
        }
        return head;
    }
};
