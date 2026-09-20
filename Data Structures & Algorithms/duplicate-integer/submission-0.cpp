class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> mm;
        for(auto &el: nums){
            ++mm[el];
        }

        for(auto &[a, b]: mm){
            if(b>1) return true;
        }
        return false;
    }
};