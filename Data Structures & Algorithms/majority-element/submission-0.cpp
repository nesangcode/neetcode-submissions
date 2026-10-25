class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int now = 0;
        int cur = 0;
        for(auto &el: nums){
            if(cur==0){
                ++cur;
                now = el;
                continue;
            }

            if(now!=el){
                --cur;
                continue;
            }
            ++cur;
        }
        return now;
    }
};