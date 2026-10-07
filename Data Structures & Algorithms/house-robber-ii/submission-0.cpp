class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 3){
            int mx = 0;
            for(auto &el: nums){
                mx=max(el, mx);
            }
            return mx;
        }

        

        
        vector<int> dp(nums.size(), 0), dp2(nums.size(), 0);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);

        dp2[0] = 0;
        dp2[1] = nums[1];

        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(nums[i]+dp[i-2], dp[i-1]);
            dp2[i] = max(nums[i]+dp2[i-2], dp2[i-1]);
        }
        return max(nums.back()+dp2[nums.size()-3], dp[nums.size()-2]);
    }
};
