class Solution {
public:
    bool pos(vector<int> &w, int &mxw, int &days){
        int i=0;
        int sum=0;
        while(i<w.size()){
            int now = w[i];
            int j = i+1;
            if(now > mxw) return false;

            while(j<w.size() && now+w[j]<=mxw){
                now += w[j++];
            }
            ++sum;
            i = max(j, i+1);
        }
        return sum <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1,r=500*50000;
        while(l<r){
            int mid = (l+r)/2;
            if(pos(weights, mid, days)){
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return r;
    }
};