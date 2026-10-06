class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        int mx = max(dp[0], dp[1]);
        for(int i = 2; i < dp.size(); i++){
            dp[i] = nums[i]+dp[i-2];
            if(i>=3) dp[i] = max(dp[i], nums[i]+dp[i-3]);
            mx=max(mx, dp[i]);
        }
        return mx;
    }
};
