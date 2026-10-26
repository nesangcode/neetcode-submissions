class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefr;
        int now = 0;
        prefr[0] = 1;
        int sum = 0;

        for(auto &el: nums){
            now += el;
            sum += prefr[now-k];
            prefr[now]++;
        }
        return sum;
    }
};