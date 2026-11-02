class Solution {
public:
    int mySqrt(int x) {
        int l=0, r=46340;
        while(l<=r){
            int mid=(l+r)/2;
            int res = mid*mid;
            if(res < x){
                l = mid+1;
            } else if(res > x){
                r = mid-1;
            } else {
                return mid;
            }
        }
        return min(l, r);
    }
};