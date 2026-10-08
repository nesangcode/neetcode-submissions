class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<bool>> computed;
    
    bool isPalin(string &s, int l, int r){
        if(l>r) return true;
        if(l < 0||r>=s.size()) return true;
        if(computed[l][r]) return dp[l][r];
        if(l==r) return true;
        computed[l][r] = true;
        if(s[l]==s[r]){
            if(isPalin(s,l+1,r-1)){
                return dp[l][r]=true;
            }
        }
        return dp[l][r]=false;
    }
    string longestPalindrome(string s) {
        dp.assign(s.size(), vector<bool>(s.size(), 0));
        computed.assign(s.size(), vector<bool>(s.size(), 0));
        int mxs=0;
        pair<int,int> res = {0, 0};
        for(int i = 0; i < s.size(); i++){
            for(int j = i+1; j < s.size(); j++){
                if(isPalin(s, i, j)){
                    if(j-i+1 > mxs){
                        mxs = j-i+1;
                        res = {i, j};
                    }
                }
            }
        }
        return s.substr(res.first, res.second-res.first+1);
    }

};
