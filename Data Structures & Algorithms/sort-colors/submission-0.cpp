class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> hi(3, 0);
        for(auto &el: nums){
            ++hi[el];
        }
        int i=0,b=0;
        while(i<nums.size()){
            while(hi[b]==0) b++;
            while(hi[b]>0){
                nums[i++] = b;
                hi[b]--;
            }
        }
    }
};