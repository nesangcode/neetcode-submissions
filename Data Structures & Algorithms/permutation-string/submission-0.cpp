class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        int cnt[26] = {0};
        int lock = 0;
        for(auto &ch: s1){
            if(cnt[ch-'a']==0){
                ++lock;
            }
            ++cnt[ch-'a'];
        }

        for(int i = 0; i < s1.size(); i++){
            if(cnt[s2[i]-'a']==1){
                --lock;
            }
            --cnt[s2[i]-'a'];
        }

        if(lock==0) return true;

        for(int i = s1.size(); i < s2.size(); i++){
            if(cnt[s2[i-s1.size()]-'a']==0){
                ++lock;
            }

            ++cnt[s2[i-s1.size()]-'a'];
            if(cnt[s2[i]-'a']==1){
                --lock;
            }
            cnt[s2[i]-'a']--;
            if(lock==0) return true;
        }

        return false;
    }
};
