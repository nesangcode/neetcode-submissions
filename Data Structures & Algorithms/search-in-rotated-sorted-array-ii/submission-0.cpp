class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto &el: nums){
            if(el==target) return true;
        } return false;
    }
};