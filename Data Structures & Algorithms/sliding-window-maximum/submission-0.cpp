class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;

        vector<int> fin;

        for(int i = 0; i < k; i++){
            ms.insert(nums[i]);
        }

        fin.emplace_back(*ms.rbegin());

        for(int i = k; i < nums.size(); i++){
            ms.erase(ms.find(nums[i-k]));
            ms.insert(nums[i]);
            fin.emplace_back(*ms.rbegin());
        }

        return fin;
    }
};
