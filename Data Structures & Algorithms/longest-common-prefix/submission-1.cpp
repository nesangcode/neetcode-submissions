class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        string str;
        bool brk = false;
        while(!brk && i < strs[0].size()){
            for(int j = 1; j < strs.size(); j++){
                if(i >= min(strs[j-1].size(), strs[j].size())){
                    brk = true;
                    break;
                }
                if(strs[j-1][i]!=strs[j][i]){
                    brk = true;
                    break;
                }
            }
            if(!brk) str += strs[0][i++];
        }
        return str;
    }
};