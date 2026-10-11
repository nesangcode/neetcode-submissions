class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(amount+1, -2);
        int res = cc(coins, amount);
        return cc(coins, amount);
    }

    int cc(vector<int>&coins, int amount){
        if(amount < 0) return 0;
        if(amount == 0) return 0;
        if(dp[amount]!=-2) return dp[amount];
        int sum=0;
        int mn=INT_MAX;
        for(auto &el: coins){
            if(el>amount) continue;
            int res = cc(coins, amount-el);
            if(res==-1) continue;
            
            mn=min(mn,res);
        }
        if(mn==INT_MAX) return dp[amount]=-1;
        return dp[amount]=mn+1;
    }
};
