class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis(nums.size(), 1);
        int mx = 1;
        for(int i = 0; i < lis.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j]<nums[i]){
                    lis[i] = max(lis[j]+1, lis[i]);
                    mx = max(mx, lis[i]);
                }
            }
        }
        return mx;
    }
};
