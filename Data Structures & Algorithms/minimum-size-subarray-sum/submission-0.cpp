class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int mn = INT_MAX;
        int sum = 0;

        while(j < nums.size()){
            sum += nums[j];
            while(i<=j&&sum>=target){
                mn=min(mn, j-i+1);
                sum -= nums[i++];
            }
            j++;
        }

        if(mn==INT_MAX)return 0;
        return mn;
    }
};