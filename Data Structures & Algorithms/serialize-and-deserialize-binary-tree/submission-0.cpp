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

class Codec {
public:

    int trav(TreeNode* now, int num, vector<int> &val, vector<int> &io){
        if(now==nullptr) return num;
        int ori = ++num;
        val[ori] = now->val;

        num = trav(now->left, num, val, io);
        io.emplace_back(ori);
        num = trav(now->right, num, val, io);

        return num;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr) return "";

        vector<int> val(10002, -1001);
        vector<int> io;

        trav(root, -1, val, io);
        string ioo;
        string vals;
        for(int i = 0;i<io.size();i++){
            if(i!=0) ioo+=",";
            ioo+=to_string(io[i]);
        }

        for(int i = 0; i < val.size(); i++){
            if(val[i]==-1001) break;
            if(i!=0) vals+=",";
            vals+=to_string(i)+","+to_string(val[i]);
        }

        return ioo+";"+vals+";";
    }

    pair<int,int> to_num(string &str, int st){
        int res=0;
        while(st < str.size()){
            bool isnum = str[st]>='0'&&str[st]<='9';
            if(!isnum) break;
            res*=10;
            res+=str[st]-'0';
            ++st;
        }
        return pair(res, st);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        vector<int> io;
        int itr=0;
        while(itr<data.size()){
            auto [res, itr2] = to_num(data, itr);
            io.emplace_back(res);
            itr=itr2;
            if(itr<data.size()&&data[itr]==';') break;
            else if(itr<data.size()&&data[itr]==',')++itr;
        }

        vector<int> val(io.size()+6, -1001);
        ++itr;
        while(itr<data.size()){
            auto [res, itr2] = to_num(data, itr);
            auto [res2, itr3] = to_num(data, itr2+1);
            val[res]=res2;
            itr=itr3;
            if(itr<data.size()&&data[itr]==';') break;
            else if(itr<data.size()&&data[itr]==',')++itr;
        }

        // precompute idx
        vector<int> idx(io.size()+6, -1);
        for(int i = 0; i < io.size();i++){
            idx[io[i]] = i;
        }

        // for(auto &el: io) cout << el << " ";
        // cout << '\n';
        // return nullptr;
        TreeNode* head = new TreeNode(val[0]);
        stack<pair<TreeNode*,int>> stt;
        stt.emplace(head, idx[0]);
        for(int i = 1; i < io.size(); i++){
            TreeNode* last = nullptr;

            while(!stt.empty()){
                auto [tn, ixn] = stt.top();
                if(ixn <= idx[i]){
                    last = tn;
                    stt.pop();
                    continue;
                }
                break;
            }

            TreeNode* nw = new TreeNode(val[i]);
            if(last==nullptr){
                stt.top().first->left = nw;
            } else {
                last->right = nw;
            }

            stt.emplace(nw, idx[i]);
        }

        return head;


    }
};
