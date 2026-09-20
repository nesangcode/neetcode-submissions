class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size()-1;

        while((r-l)>1){
            int mid = (l+r)/2;
            int mid1 = (l+mid)/2;
            int mid2 = (mid+r)/2;
            if(nums[l] <= nums[r]) break;
            if(nums[r] <= nums[mid2]){
                l = mid2;
                continue;
            }

            if(nums[mid2] <= nums[mid]){
                l = mid;
                r = mid2;
                continue;
            }

            if(nums[mid] <= nums[mid1]){
                l = mid1;
                r = mid;
                continue;
            }

            if(nums[mid1] <= nums[l]){
                r = mid1;
                continue;
            }
        }

        if(l!=r){
            if(nums[r]<nums[l]) l = r;
        }
        return nums[l];
    }
};
