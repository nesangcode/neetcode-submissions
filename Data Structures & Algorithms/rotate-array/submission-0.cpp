class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int i = 0;
        int a=nums.size()-k,b=k;

        while(a!=0&&b!=0){
            if(a >= b){
                for(int x = nums.size()-b; x < nums.size(); x++){
                    swap(nums[i++], nums[x]);
                }
                a -= b;
            } else {
                for(int x = nums.size()-b; x < nums.size()-b+a; x++){
                    swap(nums[i++], nums[x]);
                }
                b -= a;
            }
        }
    }
};