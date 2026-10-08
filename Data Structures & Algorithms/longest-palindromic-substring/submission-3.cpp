class Solution {
public:
    vector<vector<pair<int, int>>> dp;
    vector<vector<int>> pali;
    pair<int, int> trav(string &s, int l, int r){
        if(l < 0||r>=s.size()) return {0, -1};
        if(l>r) return {0, -1};
        if(dp[l][r].first!=-1) return dp[l][r];
        if(l==r) return dp[l][r] = {l, l};
        if(s[l]==s[r]){
            pair<int,int> al=trav(s, l+1, r-1);
            if(max(0, al.second-al.first+1) == max(0, r-l-1)) return dp[l][r] = {l, r};
        }

        pair<int, int> lef = trav(s, l, r-1);
        pair<int, int> rit = trav(s, l+1, r);
        if(lef.second-lef.first >= rit.second-rit.first){
            return dp[l][r] = lef;
        }
        return dp[l][r] = rit;
    }
    string longestPalindrome(string s) {
        dp.assign(s.size(), vector<pair<int, int>>(s.size(), {-1, -1}));
        pair<int,int> res = trav(s, 0, s.size()-1);
        return s.substr(res.first, res.second-res.first+1);
    }

};
