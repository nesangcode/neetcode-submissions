class Solution {
public:
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(), -1);
        return fi(0, s, wordDict);
    }

    bool ok(int n, string &s, string &hi){
        if(n+hi.size() > s.size()) return false;
        int j=0;
        for(int i = n; i < n+hi.size(); i++, j++){
            if(s[i]!= hi[j]) return false;
        }
        return true;
    }
    bool fi(int n, string &s, vector<string> &wordDict){
        if(n==s.size()) return true;
        if(dp[n]!=-1) return dp[n];

        for(auto &el: wordDict){
            if(ok(n, s, el)){
                if(fi(n+el.size(), s, wordDict)){
                    return dp[n] = true;
                }
            }
        }
        return dp[n] = false;
    }
};
