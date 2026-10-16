class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        dp[0][0] = text1[0]==text2[0];
        for(int i = 1; i < text2.size(); i++){
            int hi = text1[0]==text2[i];
            dp[0][i] = max(hi, dp[0][i-1]);
        }

        for(int i = 1; i < text1.size(); i++){
            int hi = text1[i]==text2[0];
            dp[i][0] = max(hi, dp[i-1][0]);
        }

        for(int i = 1; i < text1.size(); i++){
            for(int j = 1; j < text2.size(); j++){
                dp[i][j] = max(dp[i-1][j],
                max(
                    dp[i][j-1],
                    (text1[i]==text2[j])
                    +
                    dp[i-1][j-1]
                ));
            }
        }

        return dp.back().back();
    }
};
