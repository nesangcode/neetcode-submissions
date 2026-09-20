class Solution {
public:
    bool isAnagram(string s, string t) {
        int alp[27] = {0};
        int alp2[27] = {0};
        for(auto &el: s){
            alp[el-'a']++;
        }

        for(auto &el: t){
            alp2[el-'a']++;
        }

        bool ans = true;
        for(int i = 0; i < 26; i++){
            ans &= alp[i]==alp2[i];
        }

        return ans;

    }
};
