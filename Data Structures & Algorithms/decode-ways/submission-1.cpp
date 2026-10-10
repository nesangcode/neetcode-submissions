class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        dp[s.size()] = 1;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i]=='0') continue;
            dp[i] += dp[i+1];
            if((i+2) > s.size()) continue;
            if(s[i]>='3') continue;
            if(s[i]=='2' && s[i+1] >= '7') continue;
            dp[i] += dp[i+2];
        }
        return dp[0];
    }
};
