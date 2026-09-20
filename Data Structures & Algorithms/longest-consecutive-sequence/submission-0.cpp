class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mx_l;
        int f_mx=0;
        for(auto &el: nums){
            mx_l[el] = max(mx_l[el], mx_l[el-1]+1);
            f_mx = max(f_mx, mx_l[el]);
        }
        return f_mx;
    }
};
