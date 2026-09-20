class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0; int itr = 0;
        int lgth = 0;
        int mx = 0;
        unordered_map<char, int> alp;
        
        while(itr < s.length()){
            while(alp[s[itr]]){
                alp[s[i++]] = false;
                --lgth;
            }

            alp[s[itr]] = true;
            ++lgth, ++itr;
            mx = max(mx, lgth);
        }
        return mx;
    }
};
