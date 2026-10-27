class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0) return false;
        unordered_set<int> s;

        for(int i = 0; i < min(k+1, (int)nums.size()); i++){
            if(s.count(nums[i])) return true;
            s.insert(nums[i]);
        }

        for(int i = k+1; i < nums.size(); i++){
            s.erase(nums[i-(k+1)]);
            if(s.count(nums[i])) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};