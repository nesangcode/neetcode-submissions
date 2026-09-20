class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> fs;
        set<tuple<int,int,int>> res;
        vector<vector<int>> fin;

        for(int i = nums.size()-2; i > 0; i--){
            fs[nums[i+1]]++;
            for(int j = 0; j < i; j++){
                if(fs[-(nums[i]+nums[j])] > 0){
                    vector<int> v = {nums[i], -(nums[i]+nums[j]), nums[j]};
                    sort(v.begin(), v.end());
                    res.emplace(v[0], v[1], v[2]);
                }
            }
        }

        for(auto &[a, b, c]: res){
            fin.push_back({a, b, c});
        }
        return fin;
    }
};
