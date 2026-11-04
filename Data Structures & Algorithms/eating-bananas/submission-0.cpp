class Solution {
public:
    int tm(vector<int> &piles, int &sp){
        int sum = 0;
        for(auto &el: piles){
            sum += el/sp + (el%sp!=0);
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=1'000'000'000;
        while(l<r){
            int mid = (l+r)/2;
            int res = tm(piles, mid);
            if(res <= h){
                r=mid;
            } else {
                l = mid+1;
            } 
        }
        return r;
    }
};
