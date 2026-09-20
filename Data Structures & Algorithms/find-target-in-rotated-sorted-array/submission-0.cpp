class Solution {
public:
    int search(vector<int>& nums, int target) {
        // if arr[l] <= arr[mid]
        //     if target in range(arr[l], arr[mid])
        //          r = mid;
        //     else: l = mid+1
        // else:
        //     if target >= arr[l]:
        //         r = mid-1;
        //     else if target > arr[mid]:
        //         l = mid+1
        //     else r = mid-1, l++;
        int l=0, r=nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(target == nums[mid]){
                l = mid, r = mid;
                break;
            }

            if(nums[l] <= nums[mid]){
                if(target >= nums[l] && target <= nums[mid]){
                    r = mid;
                } else {
                    l = mid+1;
                }
            } else {
                if(target >= nums[l]){
                    r = mid;
                } else if(target > nums[mid]){
                    l = mid+1;
                } else {
                    r = mid-1;
                    l++;
                }
            }
        }

        if(l < nums.size() && nums[l]==target) return l;
        else return -1;
    }
};
