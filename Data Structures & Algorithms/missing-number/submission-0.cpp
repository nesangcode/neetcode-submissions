class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = (nums.size()+1)*(nums.size())/2;
        for(auto &el: nums){
            ans -= el;
        }
        return ans;
    }
};
