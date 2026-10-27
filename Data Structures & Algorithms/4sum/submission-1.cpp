class Solution {
public:

    vector<vector<int>> twoSum(vector<int>& nums, long long &target, int l, int r){
        vector<vector<int>> fin;
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum > target){
                r--;
            } else if(sum < target){
                l++;
            } else {
                int i = l, j = r;

                while(l<r && nums[l]==nums[i]){
                    l++;
                }
                while(l<r && nums[r]==nums[j]){
                    r--;
                }

                fin.push_back({nums[i], nums[j]});
        

            }
        }
        return fin;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> fin;
        vector<int> rus;

        for(int i = 0; i < nums.size()-3; i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            rus.emplace_back(nums[i]);
            for(int j = i+1; j < nums.size()-2; j++){
                long long hi = 1LL*target-nums[i]-nums[j];;
                if(hi < -2'000'000'000 || hi > 2'000'000'000) continue;
                if(j>(i+1) && nums[j]==nums[j-1]) continue;
                rus.emplace_back(nums[j]);
                vector<vector<int>> res = twoSum(nums, hi, j+1, nums.size()-1);
                for(auto &v: res){
                    rus.emplace_back(v[0]);
                    rus.emplace_back(v[1]);
                    fin.emplace_back(rus);
                    rus.pop_back();
                    rus.pop_back();
                }
                rus.pop_back();
            }
            rus.pop_back();
        }
        return fin;
    }
};