class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = 0;
        for(int i = 0; i < nums.size(); i++, mx--){
            if(i==(nums.size()-1)) return true;
            mx = max(mx, nums[i]);

            if(mx <= 0) return false;
        }
        return true;
    }
};
