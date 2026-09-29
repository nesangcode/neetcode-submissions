class Solution {
public:
    vector<vector<int>> glob;
    
    void trav(int sum, int &target, int d, vector<int> &v, vector<int> &nums){
        if(sum==target){
            glob.push_back(v);
            return;
        }

        if(d==nums.size()) return;

        if(nums[d]+sum <= target){
            v.emplace_back(nums[d]);
            trav(sum+nums[d], target, d, v, nums);
            v.pop_back();
        }

        trav(sum, target, d+1, v, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> v = {};
        trav(0, target, 0, v, nums);
        return glob;
    }
};
