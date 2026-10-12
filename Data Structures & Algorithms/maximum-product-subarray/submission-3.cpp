class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> prod(nums.size(), 0);
        vector<int> pred(nums.size(), INT_MAX);
        pred[0] = nums[0];
        prod[0] = nums[0];
        int mx = nums[0];
        for(int i = 1; i < nums.size(); i++){
        
            prod[i] = max(
                nums[i], max(
                    nums[i]*prod[i-1],
                    nums[i]*pred[i-1]
                ));
            
            pred[i] = min(
                nums[i], min(
                    nums[i]*prod[i-1],
                    nums[i]*pred[i-1]
                )
            );
            mx = max(mx, prod[i]);
        }

        return mx;
    }
};
