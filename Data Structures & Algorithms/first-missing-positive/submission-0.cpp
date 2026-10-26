class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> b(nums.size()+2, 0);
        int cnt = 1;
        for(auto &el: nums){
            if(el <= 0 || el > nums.size()) continue;
            b[el] = true;

            while(cnt <= nums.size() && b[cnt]){
                ++cnt;
            }
        }
        return cnt;
    }
};