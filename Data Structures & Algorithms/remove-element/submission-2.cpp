class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while(j < nums.size()){
            while(i < nums.size() && nums[i]!=val){
                i++;
            }
            j = max(j, i+1);

            while(j < nums.size() && nums[j]==val){
                j++;
            }

            while(j < nums.size() && nums[i]==val && nums[j]!=val){
                swap(nums[i], nums[j]);
                i++, j++;
            }
        }

        return i;
    }
};