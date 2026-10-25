class Solution {
public:
    void sorti(vector<int> &nums, int l, int r){
        if(r==l) return;
        int mid = (l+r)/2;
        sorti(nums, l, mid);
        sorti(nums, mid+1, r);

        vector<int> a;
        int i=l,j=mid+1;
        while(i<=mid&&j<=r){
            if(nums[i]<=nums[j]){
                a.emplace_back(nums[i++]);
            } else {
                a.emplace_back(nums[j++]);
            }
        }
        while(i<=mid) a.emplace_back(nums[i++]);
        while(j<=r) a.emplace_back(nums[j++]);
        

        for(int k = l,b=0; k <= r; k++, b++){
            nums[k] = a[b];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        sorti(nums, 0, nums.size()-1);
        return nums;
    }
};