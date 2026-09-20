class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suf, pref;
        suf.emplace_back(nums.back());
        pref.emplace_back(nums.front());
        for(int i = 1; i < nums.size(); i++){
            pref.emplace_back(pref.back()*nums[i]);
        }

        for(int i = nums.size()-2; i >= 0; i--){
            suf.emplace_back(suf.back()*nums[i]);
        }
        reverse(suf.begin(), suf.end());

        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            int num = 1;
            if(i > 0) num *= pref[i-1];
            if(i < (nums.size()-1)) num *= suf[i+1];
            res.emplace_back(num);
        }
        return res;
    }
};
