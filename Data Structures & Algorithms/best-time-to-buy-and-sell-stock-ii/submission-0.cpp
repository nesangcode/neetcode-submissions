class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof=0;
        int now= prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] > now){
                prof += prices[i]-now;
            }
            now = prices[i];
        }
        return prof;
    }
};