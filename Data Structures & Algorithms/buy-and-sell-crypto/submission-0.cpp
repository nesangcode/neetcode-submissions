class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx = INT_MIN;
        int mx_p = 0;

        vector<int> prf(prices.size()+1, INT_MAX);
        for(int i = 1; i <= prices.size(); i++){
            prf[i] = min(prf[i-1], prices[i-1]);
        }

        for(int i = prices.size()-1; i > 0; i--){
            mx = max(mx, prices[i]);
            mx_p = max(mx_p, mx-prf[i]);

        }
        return mx_p;
    }
};
