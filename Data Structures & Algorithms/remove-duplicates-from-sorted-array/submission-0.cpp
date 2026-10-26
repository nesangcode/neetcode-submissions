class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]==nums[i-1]){
                nums[i-1]=-101;
            }
        }

        int i=0,j=0;

        while(j<nums.size()){
            while(i<nums.size() && nums[i]!=-101){
                i++;
            }

            j=max(i+1, j);

            while(j<nums.size()&&nums[j]==-101){
                j++;
            }

            while(j<nums.size()&&nums[j]!=-101&&nums[i]==-101){
                swap(nums[i++], nums[j++]);
            }
        }

        while(nums.back()==-101) nums.pop_back();

        return nums.size();
    }
};